from flask import request, jsonify, render_template
from werkzeug.utils import secure_filename
import os
from app.vulnerability_checker import check_vulnerabilities, calculate_cvss
from app import app

def allowed_file(filename):
    return '.' in filename and filename.rsplit('.', 1)[1].lower() in app.config['ALLOWED_EXTENSIONS']

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/upload', methods=['POST'])
def upload_file():
    if 'file' not in request.files:
        return jsonify({'error': 'No file part'}), 400

    file = request.files['file']
    if file.filename == '':
        return jsonify({'error': 'No selected file'}), 400

    if file and allowed_file(file.filename):
        filename = secure_filename(file.filename)
        filepath = os.path.join(app.config['UPLOAD_FOLDER'], filename)
        
        try:
            # Create the directory if it doesn't exist
            os.makedirs(app.config['UPLOAD_FOLDER'], exist_ok=True)
            file.save(filepath)
        except Exception as e:
            return jsonify({'error': f'File upload failed: {str(e)}'}), 500
        
        # Proceed with vulnerability checking and CVSS scoring
        try:
            vulnerabilities = check_vulnerabilities(filepath)
            cvss_scores = [calculate_cvss(v) for v in vulnerabilities]
        except Exception as e:
            return jsonify({'error': f'Error processing file: {str(e)}'}), 500
        
        is_secure = "secure" if not vulnerabilities else "insecure"

        return render_template('result.html', 
                               is_secure="secure" if not vulnerabilities else "insecure", 
                               vulnerabilities=vulnerabilities, 
                               cvss_scores=cvss_scores)
    else:
        return jsonify({'error': 'File type not allowed'}), 400
    
if __name__ == '__main__':
    app.run(debug=True)
