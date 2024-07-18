$(document).ready(function() {
    $('#upload-form').on('submit', function(e) {
        e.preventDefault();
        var formData = new FormData(this);

        $.ajax({
            type: 'POST',
            url: '/upload',
            data: formData,
            contentType: false,
            processData: false,
            success: function(data) {
                var vulnerabilities = data.vulnerabilities;
                var cvssScores = data.cvss_scores;

                var vulnerabilitiesHtml = '';
                if (vulnerabilities.length === 0) {
                    vulnerabilitiesHtml = '<p class="text-muted">No vulnerabilities found!</p>';
                } else {
                    vulnerabilities.forEach(function(vulnerability) {
                        vulnerabilitiesHtml += '<p><strong>' + vulnerability.type + '</strong>: ' + vulnerability.description + ' (Line: ' + vulnerability.line + ')</p>';
                    });
                }
                $('#vulnerabilities').html(vulnerabilitiesHtml);

                var cvssScoresHtml = '';
                if (cvssScores.length === 0) {
                    cvssScoresHtml = '<p class="text-muted">No CVSS scores available.</p>';
                } else {
                    cvssScores.forEach(function(score, index) {
                        cvssScoresHtml += '<p>Vulnerability ' + (index + 1) + ': CVSS Score = ' + score + '</p>';
                    });
                }
                $('#cvss-scores').html(cvssScoresHtml);
            },
            error: function() {
                alert('File upload failed!');
            }
        });
    });
});
