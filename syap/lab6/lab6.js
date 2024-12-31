
console.log("\nTASK 1\n");
let numbers = [1,2,3,4,5];
let [firstNumb] = numbers;
console.log(`1 элемент массива number: ${firstNumb}`);


console.log("\nTASK 2\n");
let user = {
    name: "ivan",
    age: 18
}
let admin = {
    admin: true,
    ...user
}
console.log(`Свойства user: name - ${user.name}, age - ${user.age}`);
console.log(`Свойства admin: admin - ${admin.admin}, name - ${admin.name}, age - ${admin.age}`);


console.log("\nTASK 3\n");
let store = {
    state: {
        profilePage: {
            posts: [
                {id: 1, message: 'Hi', likesCount: 12},
                {id: 2, message: 'By', likesCount: 1},
            ],
            newPostText: 'About me',
        },
        dialogsPage: {
            dialogs: [
                {id: 1, name: 'Valera'},
                {id: 2, name: 'Andrey'},
                {id: 3, name: 'Sasha'},
                {id: 4, name: 'Victor'},
            ],
            message: [
                {id: 1, message: 'hi'},
                {id: 2, message: 'hi hi'},
                {id: 3, message: 'hi hi hi'},
            ],
        },
        sidebar: [],
    },
}
let [thirdLvl] = store.state.profilePage.posts;

console.log(`Деструкторизация объекта до 3 уровня: id - ${thirdLvl.id}, message - ${thirdLvl.message}, likeCount - ${thirdLvl.likesCount}`);
store.state.profilePage.posts.forEach(like => {
    console.log(like.likesCount);
});

store.state.dialogsPage.dialogs.forEach(dialog => {
    if (dialog.id %2 == 0) {
        console.log(dialog.name);
    }
})
store.state.dialogsPage.message = store.state.dialogsPage.message.map(msg => {
    return { id: msg.id, message: 'Hello user' };
});
store.state.dialogsPage.message.forEach(msg => {
    console.log(msg.message);
})

console.log("\nTASK 4\n");

let tasks = [
    {id: 1, title: "HTML&CSS", isDone: true},
    {id: 2, title: "JS", isDone: true},
    {id: 3, title: "ReactJS", isDone: false},
    {id: 4, title: "Rest API", isDone: false},
    {id: 5, title: "GraphQL", isDone: false},
];
let newTask = {id: 6, title: "XML", isDone: true};
let resultTast = [...tasks, newTask];
console.log(resultTast);

console.log("\nTASK 5\n");

function sumValues(x,y,z){
    return x+y+z;
}

let array = [1,2,3];
console.log(sumValues(...array))