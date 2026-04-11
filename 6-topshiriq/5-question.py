class Professor:
    def __init__(self, id, name):
        self.id = id
        self.name = name


class Course:
    def __init__(self, id, name, professor):
        self.id = id
        self.name = name
        self.professor = professor  

class Student:
    def __init__(self, id, name, age, courses):
        self.id = id
        self.name = name
        self.age = age
        self.courses = courses


professor1 = Professor(1, "Dr. Smith")

course1 = Course(1, "Mathematics", professor1)
course2 = Course(2, "Physics", professor1)

student1 = Student(1, "Alice", 20, [course1, course2])