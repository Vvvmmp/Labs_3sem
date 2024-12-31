function validateInput(event) {
    const input = event.target;
    const regex = /^[A-Za-zА-Яа-яЁё\s]*$/; 
    const value = input.value;

    if (value.length > 20) {
        alert("Длина должна быть не более 20 символов.");
        input.value = value.slice(0, 20); 
        return;
    }

    if (!regex.test(value)) {
        alert("Разрешены только буквы русского и английского алфавита.");
        input.value = ''; 
    }
}

function validateEmail(event) {
    const input = event.target;
    const value = input.value;

    const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z]{2,5}\.[a-zA-Z]{2,3}$/;

    if (value.includes(' ')) {
        alert("E-mail не должен содержать пробелы.");
        input.value = ''; 
        return;
    }

    if (!emailRegex.test(value)) {
        alert("Неверный формат E-mail. Убедитесь, что он соответствует формату: @ххххх.ххх");
        input.value = ''; 
    }
}

function validatePhone(event) {
    const input = event.target;
    const value = input.value;

    const phoneRegex = /^\(0\d{2}\)\d{3}-\d{2}-\d{2}$/;

    if (!phoneRegex.test(value)) {
        alert("Неверный формат номера телефона. Убедитесь, что он соответствует формату: (0xx)xxx-xx-xx");
        input.value = ''; 
    }
}

function validateMessage(event) {
    const value = event.target.value;

    if (value.length > 250) {
        alert("Длина должна быть не более 250 символов.");
        input.value = value.slice(0, 250); 
        return;
    }
}

function validateForm(event) {
    const city = document.querySelector('select[name="city"]').value;
    const isBGTU = document.getElementById('bstu').checked;
    const course = document.getElementById('course').value;

    if (city != 'Минск') {
        if (!confirm("Вы уверены, что ваш город не Минск?")) {
            event.preventDefault(); 
            return;
        }
    }

    if (course != '3') {
        if (!confirm("Вы уверены, что вы учитесь не на 3 курсе?")) {
            event.preventDefault();
            return;
        }
    }

    if (!isBGTU) {
        if (!confirm("Вы уверены, что не учитесь в БГТУ?")) {
            event.preventDefault(); 
            return;
        }
    }
}