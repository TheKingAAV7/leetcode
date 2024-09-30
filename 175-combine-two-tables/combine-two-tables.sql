SELECT p.firstName,p.lastName,a.city,a.state from Person as p 
LEFT JOIN Address as a ON p.personId=a.personID;