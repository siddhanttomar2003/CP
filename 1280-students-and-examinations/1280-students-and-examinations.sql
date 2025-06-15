# Write your MySQL query statement below
Select S.student_id,S.student_name,B.subject_name,count(E.subject_name) as attended_exams
from (Students AS S JOIN Subjects B)
LEFT JOIN Examinations AS E
on S.student_id = E.student_id AND B.subject_name = E.subject_name
group by S.student_id,B.subject_name
ORDER BY S.student_id,B.subject_name;

