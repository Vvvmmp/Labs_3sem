const products = new Set();
console.log('\nЗАДАНИЕ 1\n');
function addProduct(product, quantity) {
    const existingProduct = Array.from(products).find(p => p.name === product);
    
    if (existingProduct) {
        existingProduct.quantity += quantity; 
        console.log(`Обновлён продукт: ${product}, новое количество: ${existingProduct.quantity}`);
    } else {
        products.add({ name: product, quantity: quantity }); 
        console.log(`Добавлен продукт: ${product}, количество: ${quantity}`);
    }
}

function deleteProduct(product) {
    const existingProduct = Array.from(products).find(p => p.name === product);
    
    if (existingProduct) {
        products.delete(existingProduct);
        console.log(`Удалён продукт: ${product}`);
    } else {
        console.log(`Продукт ${product} не найден.`);
    }
}

function hasProduct(product) {
    const exists = Array.from(products).some(p => p.name === product);
    console.log(`Продукт ${product} ${exists ? 'имеется' : 'не найден'} в списке.`);
    return exists;
}

function getProductQuantity(product) {
    const existingProduct = Array.from(products).find(p => p.name === product);
    
    if (existingProduct) {
        console.log(`Количество товара ${product}: ${existingProduct.quantity}`);
        return existingProduct.quantity;
    } else {
        console.log(`Продукт ${product} не найден.`);
        return 0;
    }
}

addProduct('Бананы', 5);
addProduct('Помидоры', 20);
addProduct('Лук', 10);
addProduct('Бананы', 3); 

console.log('\nТекущий список продуктов:');
products.forEach(product => console.log(`${product.name}: ${product.quantity}`));

hasProduct('Бананы');
getProductQuantity('Бананы'); 
deleteProduct('Лук'); 
getProductQuantity('Лук');











console.log('\nЗАДАНИЕ 2\n');

const students = new Set();
students.add({ FIO: 'Лужецкий В К', testBook: 70123, groupNumber: 8});
students.add({ FIO: 'Александрович И А', testBook: 70111, groupNumber: 7});
students.add({ FIO: 'Семёнов Д В', testBook: 70133, groupNumber: 6});
printStudent(students);
function printStudent(students){
    console.log('\n\n\n');
    for (let s of students) {
        console.log(`Имя: ${s.FIO}, группа: ${s.groupNumber}, № зачётки: ${s.testBook}`);
    }
}
function addStudent(student) {
    for (let s of students) {
        if (s.FIO === students.FIO) {
            console.log('Студент уже добавлен.');
            return;
        }
   }
   students.add(student);
}
addStudent({FIO: 'Бамб Л И', testBook: 70333, groupNumber: 3});
printStudent(students);

function deleteByTestBook(number) {
    for (let s of students) {
        if (s.testBook === number) {
            students.delete(s); 
            console.log('Студент удалён.');
            return;
        }
    }
    console.log('Студента с таким номером нету');
}

let nTestBook = 70123;
deleteByTestBook(nTestBook);
printStudent(students);

function sortByGroup(students) {
    const sorted = Array.from(students).sort((a, b) => a.groupNumber - b.groupNumber);
    return sorted; 
}
const sortedStudents = sortByGroup(students);
printStudent(sortedStudents);

function sortByNumberTestBook(students) {
    const sorted = Array.from(students).sort((a, b) => a.testBook - b.testBook);
    return sorted; 
}
const sortedStudents1 = sortByNumberTestBook(students);
printStudent(sortedStudents1);
















console.log('\nЗАДАНИЕ 3\n');

const items = new Map();

items.set(1, { name: 'Чипсы', quantity: 300, price: '2$' });
items.set(2, { name: 'Кола', quantity: 100, price: '3$' });
items.set(3, { name: 'Чай', quantity: 1000, price: '5$' });
items.set(4, { name: 'Кофе', quantity: 1, price: '10.5$' });

function printItem(items) {
    console.log('\n\n');
    for (let [key, item] of items) {
        console.log(`ID: ${key}, Название: ${item.name}, Количество: ${item.quantity}, Цена: ${item.price}`);
    }
}

printItem(items);

function addItem(id, name, quantity, price){
    if(items.has(id)) {
        console.log('Товар уже есть в списке');
        return;
    }
    items.set(id, {name, quantity, price});
}
addItem(5, 'Сигареты', 10, '2000$');
addItem(1, 'Чипсы', 300, '2$');
printItem(items);

function deleteItem(id){
    if(items.has(id)) {
        items.delete(id);
        console.log('Товар удалён');
        return;
    }
    console.log('Товара нет в списке');
}
deleteItem(1);
deleteItem(6);
printItem(items);

function deleteItemByName(name){
    for (let [key, item] of items) {
        if( item.name.toLowerCase() === name.toLowerCase()) {
            items.delete(key);  
            console.log(`Товар ${name} удалён`);
            return;
        }
    }
    console.log('Товара нет в списке');
}
deleteItemByName('Кола');
deleteItemByName('крупа');
printItem(items);

function removeFullItems(items){
    for (let [key, item] of items) {
       item.quantity +=1;
       console.log(`Кол-во товара ${item.name} увеличено на 1`);
    }

}   
removeFullItems(items);
printItem(items);

function removePrice(name){
    for (let [key, item] of items) {
       if(name.toLowerCase() === item.name.toLowerCase()) {
        let priceNumber = parseFloat(item.price.replace(/[^0-9.]/g, '')); 
        priceNumber += 5; 
        item.price = `${priceNumber}$`; 
        console.log(`Товар ${name} повышен в цене на 5$`);
        return;
       }
    }
    console.log(`Товар ${name} не найден.`);
}   
removePrice('Чай');
printItem(items);

function countFullPositionWithTotalAmount(students) {
    let countPosition = students.size;
    let totalAmount = 0;
    console.log(`\nВсего позиций: ${countPosition}`);
    for (let [key, item] of items) {
        let priceNumber = parseFloat(item.price.replace(/[^0-9.]/g, ''));
        totalAmount += priceNumber;
    }
    totalAmount = `${totalAmount}$`; 
    console.log(`Сумма всех товаров: ${totalAmount}`);
}
countFullPositionWithTotalAmount(students)





let cache = new WeakMap();

function process(obj) {
  if (!cache.has(obj)) {
    let result = Date.now() * 10 + obj.name.length;
    cache.set(obj, result);
  }

  return cache.get(obj);
}


let obj = {name: 'Joy' };

let result1 = process(obj); 
console.log(result1);
let result2 = process(obj); 
console.log(result2);
obj = null;



