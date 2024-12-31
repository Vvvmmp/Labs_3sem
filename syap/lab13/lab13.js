class Task{
    constructor(id, name, state = false){
        this.id = id;
        this.name = name;
        this.state = state;
    }

    renewName(newName){
        this.name = newName
        return this.name;
    }
    
    renewState(newStatus){
        this.state = newStatus;
        return this.state;
    }
    changeStateTask(state){
        this.state = state;
    }

}

class Todolist{
    constructor(id, name){
        this.id = id;
        this.name = name;
        this.tasks = [];
    }

    newName(newName){
        this.name = newName;
    }

    addTask(task) {
        this.tasks.push(task);
    }


    filterTasksByStatus(status) {
        return this.tasks.filter(task => task.state === status);
    }

    
}


document.addEventListener("DOMContentLoaded", () => {
const todolist1 = new Todolist(1, "todolist1");

const input = document.querySelector("input");
const addButton = document.querySelector("button");
const showAll = document.querySelector("#showAll");
const showTrue = document.querySelector("#showTrue");
const showFalse = document.querySelector("#showFalse");
const taskContainer = document.querySelector("#taskContainer");

let taskId= 1;
function viewTasks(tasks){
    taskContainer.innerHTML = "";
    tasks.forEach(task => {
        const taskDiv = document.createElement("div");
        taskDiv.className = "task";

        const settingButton = document.createElement("button");
        settingButton.id = "Set";
        settingButton.textContent = "Редактировать";

        settingButton.addEventListener("click", ()=>{
            const a = prompt("Введите обновлённое название задачи");
            task.renewName(a);
            viewTasks(todolist1.tasks); 
        });

        const removeButton = document.createElement("button");
        removeButton.id = "Remove";
        removeButton.textContent = "Удалить";

        removeButton.addEventListener("click", ()=>{
            let index = todolist1.tasks.indexOf(task);
            if(index != -1) todolist1.tasks.splice(index, 1);
            taskId--;
            viewTasks(todolist1.tasks);
        });

        const taskName = document.createElement("p");
        taskName.textContent = task.name;

        const taskCheckbox = document.createElement("input");
        taskCheckbox.type = "checkbox";
        taskCheckbox.checked = task.state === true;
        taskCheckbox.onchange = () => {
            task.changeStateTask(taskCheckbox.checked ? true : false);
            viewTasks(todolist1.tasks);
        };

        taskDiv.appendChild(taskCheckbox);
        taskDiv.appendChild(taskName);
        taskDiv.appendChild(settingButton);
        taskDiv.appendChild(removeButton);
        taskContainer.appendChild(taskDiv);

    });
}

addButton.addEventListener("click", () =>{
    const taskName = input.value.trim();
    if(taskName) {
        const newTask = new Task(taskId++, taskName, false);
        todolist1.addTask(newTask);
        input.value = "";
        viewTasks(todolist1.tasks);
    }
});

showAll.addEventListener("click", ()=> {
    viewTasks(todolist1.tasks)
});

showTrue.addEventListener("click", ()=>{
    viewTasks(todolist1.filterTasksByStatus(true));
});

showFalse.addEventListener("click", ()=>{
    viewTasks(todolist1.filterTasksByStatus(false));
});


const task1 = new Task(1, "Сделать сяп", false);
const task2 = new Task(2, "Написать кр", true);

todolist1.addTask(task1);
todolist1.addTask(task2);
viewTasks(todolist1.tasks);
});