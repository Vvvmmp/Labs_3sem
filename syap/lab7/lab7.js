console.log("\nЗАДАНИЕ 1\n");

let person = {
    name: "andrew",
    age: 22,

    greet(){
        console.log(`Здравствуйте, ${this.name}`);
    },
    ageAfterYears(){
        console.log(`Ваш возраст, ${this.age}`);
    }
};
person.greet();
person.ageAfterYears();

console.log("\nЗАДАНИЕ 2\n");

let car = {
    model: "Volvo",
    year: 2015,
    getInfo(){
        console.log(`Информация о машине:\n Модель: ${this.model}.\n Год выпуска: ${this.year}.`);
    }
};
car.getInfo();

console.log("\nЗАДАНИЕ 3\n");

function Book(title, author) {
    this.getTitle = title;
    this.getAuthor = author;
}
let book = new Book("Вий", "Гоголь");
console.log(`Название книги: ${book.getTitle}\nАвтор: ${book.getAuthor}`);


console.log("\nЗАДАНИЕ 4\n");

let team = {
    players: ["Andrew", "Bill", "Ivan", "Vladislav"],
    getPlayers(){
        console.log("Список игроков:\n");
        for(let player of this.players){
            console.log(player);
        }
    }
};
team.getPlayers();

console.log("\nЗАДАНИЕ 5\n");

const counter = (function() {
    let count = 0;
   
    return {
        increment: function(){
            count++;
            return count;
        },
        decrement: function(){
            count--;
            return count;
        },
        getCount: function(){
            return count;
        }
    }
    })();
    
    console.log(counter.increment());  
    console.log(counter.increment());       
    console.log(counter.decrement()); 
    console.log(counter.getCount());    
    
    console.log("\nЗАДАНИЕ 6\n");

    let item = {
        price: 25
    }

    console.log(`Цена объекта: ${item.price}`);

    Object.defineProperty(item, "price", {
        writable: true,
        enumerable: false,
        configurable: true
    });

    item.price = 100;
    console.log(`Цена объекта: ${item.price}`);

    delete item.price;
    console.log(`Цена объекта: ${item.price}`);

    item.price = 5;

    Object.defineProperty(item, "price", {
        writable: false,
        configurable: false
    });

    item.price = 1;
     console.log(`Цена объекта: ${item.price}`);

     delete item.price;
     console.log(`Цена объекта: ${item.price}`);
    
     console.log("\nЗАДАНИЕ 7\n");

     let circle = {
        radius: 15,
        
        get sq() {
            return `Площадь круга с радиусом ${this.radius} = ${this.radius * 2 * Math.PI}`;
        },
        get newRadius(){
            return this.radius;
        },
        set newRadius(value){
            this.radius = value;
        }
     };
  console.log(circle.sq);
  circle.newRadius = 25;
  console.log(circle.newRadius);

  console.log("\nЗАДАНИЕ 8\n");

  let car1 = {
    make: "china",
    model: "universal",
    year: 2022
  }
  Object.defineProperty(car1, "make", {
    writable: true,
    configurable: true
});
Object.defineProperty(car1, "model", {
    writable: true,
    configurable: true
});
Object.defineProperty(car1, "year", {
    writable: true,
    configurable: true
});

    car1.make = "Belarus";
    car1.model = "sedan";
    car1.year = 2024;
    console.log(`Инфо:\n${car1.make}\n${car1.model}\n${car1.year}`);

    Object.defineProperty(car1, "make", {
        writable: false,
        configurable: false
    });
    Object.defineProperty(car1, "model", {
        writable: false,
        configurable: false
    });
    Object.defineProperty(car1, "year", {
        writable: false,
        configurable: false
    });


    car1.make = "123";
    car1.model = "123";
    car1.year = 1111;
    console.log(`Инфо:\n${car1.make}\n${car1.model}\n${car1.year}`);

    console.log("\nЗАДАНИЕ 9\n");

    let number = {
        array: [1,2,3],
         sum(){
            let sum = 0;
            for(let i = 0; i < this.array.length; i++)
                sum+=this.array[i];
            return console.log(`Сумма всех элементов: ${sum}`);
        }
    };
    Object.defineProperty(number, 'sum', {
        writable: false
    });
    number.sum();

    console.log("\nЗАДАНИЕ 10\n");

    let rectangle = {
        width: 15,
        height: 10,
        get S(){
            return `Площадь прямоугольника: ${this.width*this.height}`;
        },
        get widthValue() {
            return this.width;
        },
        get heightValue() {
            return this.height;
        },
        set heightValue(value) {
            if (value < 0) {
                console.log("<0");
            } else {
                this.height = value;
            }
        },
        set widthValue(value) {
            if (value < 0) {
                console.log("<0");
            } else {
                this.width = value;
            }
        }
    };
    console.log(rectangle.S);

    console.log("\nЗАДАНИЕ 11\n");

let user1 = {
    firstName: "Ivan",
    lastName: "Ivanov",
};

Object.defineProperty(user1, 'fullName', {
    get(){
        return `${this.firstName} ${this.lastName}`;
    },
    set(value) {
        [this.firstName, this.lastName] = value.split(" ");
    }
});

console.log(user1.fullName);