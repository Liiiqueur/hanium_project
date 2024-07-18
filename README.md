# Secure Vulnerability Checker

This project is a web application for checking security vulnerabilities in code files and calculating CVSS scores.

## Setup

### Prerequisites

- Python 3.7 or higher
- Virtualenv (optional but recommended)

### Installation

1. **Clone the repository:**
    ```bash
    git clone <repository-url>
    cd secure_vuln_checker
    ```

2. **Create a virtual environment and install dependencies:**
    ```bash
    python3 -m venv venv
    source venv/bin/activate  # MacOS/Linux
    venv\Scripts\activate     # Windows
    pip install -r requirements.txt
    ```

### Running the Application

3. **Run the application:**
    ```bash
    python run.py
    ```

4. **Open your browser and go to `http://127.0.0.1:5000/`.**

### Testing

To run tests:
```bash
python -m unittest discover
