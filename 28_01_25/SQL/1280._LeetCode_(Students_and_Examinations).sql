/*
Approach

The query aims to retrieve information about students and the subjects they are enrolled in, 
along with the number of exams attended for each subject. Let's break down the approach and logic used.

s.student_id: The unique ID of the student.
s.student_name: The name of the student.
su.subject_name: The subject name from the Subjects table.
attended_exams: A scalar subquery that counts how many times a student has attended exams for the given subject.

JOIN Students s JOIN Subjects su:
This creates a Cartesian Product between Students and Subjects.
It associates every student with every subject regardless of whether they attended any exams for those subjects.
*/


SELECT s.student_id, s.student_name, su.subject_name, 
(SELECT COUNT(1) 
	FROM Examinations  
	WHERE student_id = s.student_id 
	AND subject_name = su.subject_name) AS attended_exams
FROM Students s
JOIN Subjects su
 ORDER BY s.student_id, su.subject_name