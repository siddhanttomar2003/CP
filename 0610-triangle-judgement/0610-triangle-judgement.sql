# Write your MySQL query statement below
SELECT x,y,z,IF((x+y>z) and (y+z>x) and (x+z>y) , 'Yes','No') as triangle from Triangle ;