# Write your MySQL query statement below
WITH ranked AS (
    SELECT
        student_id,
        subject,
        score,
        exam_date,
        ROW_NUMBER() OVER (
            PARTITION BY student_id, subject
            ORDER BY exam_date
        ) AS rn_first,
        
        ROW_NUMBER() OVER (
            PARTITION BY student_id, subject
            ORDER BY exam_date DESC
        ) AS rn_latest
    FROM Scores
),

first_scores AS (
    SELECT
        student_id,
        subject,
        score AS first_score
    FROM ranked
    WHERE rn_first = 1
),

latest_scores AS (
    SELECT
        student_id,
        subject,
        score AS latest_score
    FROM ranked
    WHERE rn_latest = 1
)

SELECT
    f.student_id,
    f.subject,
    f.first_score,
    l.latest_score
FROM first_scores f
JOIN latest_scores l
    ON f.student_id = l.student_id
    AND f.subject = l.subject
WHERE l.latest_score > f.first_score
ORDER BY f.student_id, f.subject;