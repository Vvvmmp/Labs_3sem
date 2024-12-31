    console.log("\n\t\t\t\t\t\t\tExercise №1\n");
    let ObjectPrototype = {
        figure: true,
        border: true
    };

    let Triangle = {
        triangle() {
            return "Это triangle";
        },
        __proto__: ObjectPrototype,
        countLines: 0
    }

    let Square = {
        square() {
        return "Это square";
        },
        __proto__: ObjectPrototype,
        color: "",
        size: ""
    }

    let Circle = {
        circle() {
            return "Это circle";
        },
        __proto__: ObjectPrototype,
        isPaintedOver: false,
        color: ""
    }
    let triangle1 = Object.create(Triangle);
    triangle1.countLines = 1;

    let triangle2 = Object.create(Triangle);
    triangle2.countLines = 3;
    console.log(`Треугольник имеет следующие свойства:
        1. figure: ${triangle2.figure}
        2. border: ${triangle2.border}
        3. triangle: ${triangle2.triangle()}
        4. countLines: ${triangle2.countLines}`);

    let square1 = Object.create(Square);
    square1.size = "big";
    square1.color = "yellow";

    let square2 = Object.create(Square);
    square2.size = "small";
    square2.color = "yellow";
    
    console.log(`Квадрат имеет следующие свойства:
        1. figure: ${square2.figure}
        2. border: ${square2.border}
        3. square: ${square2.square()}
        4. size: ${square2.size}
        5. color: ${square2.color}
        6. Квадрат имеет собств. св-во: ${square2.hasOwnProperty("size")}
        `);

    let circle1 = Object.create(Circle);
    circle1.isPaintedOver = false;

    let circle2 = Object.create(Circle);
    circle2.isPaintedOver = true;
    circle2.color = "green";
    console.log(`Круг имеет следующие свойства:
        1. figure: ${circle2.figure}
        2. border: ${circle2.border}
        3. circle: ${circle2.circle()}
        4. isPaintedOver: ${circle2.isPaintedOver}
        5. color: ${circle2.color}`);


console.log("\n\t\t\t\t\t\t\tExercise №2\n");

class Human {
    constructor(name, surname, age, address, yearOfBirth) {
        this.name = name;
        this.surname = surname;
        this.age = age;
        this.address = address;
        this.yearOfBirth = yearOfBirth;
    }
    renewAge(newAge) {
        this.age = newAge;
    }
    renewAdress(newAddress) {
        this.address = newAddress;
    }
    get getAge() {
        return this.age;
    }
    set newAge(yearOfBirth) {
        this.age = new Date().getFullYear() - yearOfBirth;
    }
}

let human = new Human("Иван", "Иванов", 20, "минская,21", 2004);
console.log(human);
human.newAge = 2000;
console.log(human.getAge);

class Student extends Human {
    constructor(name, surname, age, address, yearOfBirth, course, groups, numberOfTestBook) {
        super(name, surname, age, address, yearOfBirth);       
        this.course = course;
        this.groups = groups;
        this.getInfoFromTestBook(numberOfTestBook);
    }
    getFullName(){
        console.log(`Имя студента:${this.name}\nФамилия студента: ${this.surname}`);
    }
    getInfoFromTestBook(numberOfTestBook) {
       let firstNumb = Math.floor(numberOfTestBook / 10000000);
       this.faculty = (firstNumb == 7) ? "IT" : "Any of the others";

        let secondNumb = Math.floor((numberOfTestBook / 1000000) % 10);
       switch(secondNumb) {
            case 1: this.speciality = "ПОИТ"; break;
            case 2: this.speciality = "ИСИТ"; break;
            case 3: this.speciality = "ДЭВИ"; break;
            case 4: this.speciality = "ПОИБМС"; break;
            default: this.speciality = ""; break;
        }
            
        this.enteringYear = Math.floor((numberOfTestBook / 10000) % 100);

        this.budget = Math.floor((numberOfTestBook / 1000) % 10) === 1;
        this.ID = numberOfTestBook % 1000;
    }
}

class Faculty {
    constructor(students) {
        this.students = students;
    }
    getDev() {
        let counter = 0;
        for(let student of this.students) {
            if(student.speciality == "ДЭВИ") counter++;
        }
        console.log(`Всего студентов с ДЭВИ: ${counter}`);
    }
    getGroup(group)
    {
        for(let student of this.students) {
            if(student.groups == group) 
                console.log(student);
        }
    }
}
let student1 = new Student("Илья", "Иванов", 20, "минская, 21", 2004, 2, 5, 71201300);
let student2 = new Student("Петр", "Сергеев", 21, "минская, 22", 2003, 2, 8, 73201300);
let student3 = new Student("Андрей", "Ивов", 22, "минская, 23", 2002, 2, 8, 73201310);

let faculty = new Faculty([student1, student2, student3]);

faculty.getDev(); 
faculty.getGroup(8);