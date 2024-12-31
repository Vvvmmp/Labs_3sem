const boardElement = document.getElementById('sudoku');

const N = 9; 
const defaultBoard = Array.from({ length: N }, () => Array(N).fill(0));

function isSafe(board, row, col, num) {
    for (let x = 0; x < N; x++) {
        if (board[row][x] === num || board[x][col] === num) {
            return false; 
        }
    }

    const startRow = row - (row % 3), startCol = col - (col % 3);
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] === num) {
                return false; 
            }
        }
    }
    return true;
}

function fullFill(board) {
    for (let row = 0; row < N; row++) {
        for (let col = 0; col < N; col++) {
            if (board[row][col] === 0) {
                for (let num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num; 
                        if (fullFill(board)) {
                            return true; 
                        }
                        board[row][col] = 0; 
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}

function generatePuzzle(board, removeCount) {
    const boardCopy = JSON.parse(JSON.stringify(board)); 
    for (let i = 0; i < removeCount; i++) {
        let row = Math.floor(Math.random() * N);
        let col = Math.floor(Math.random() * N);
        while (boardCopy[row][col] === 0) {
            row = Math.floor(Math.random() * N);
            col = Math.floor(Math.random() * N);
        }
        boardCopy[row][col] = 0; 
    }
    return boardCopy;
}

function generateNewBoard() {
    const fullBoard = JSON.parse(JSON.stringify(defaultBoard)); 
    fullFill(fullBoard);
    const puzzleBoard = generatePuzzle(fullBoard, 50); 
    displayBoard(puzzleBoard);
}

function displayBoard(board) {
    boardElement.innerHTML = '';
    board.forEach((row, rowIndex) => {
        const tr = document.createElement('tr');
        row.forEach((cell, colIndex) => {
            const td = document.createElement('td');
            td.textContent = cell !== 0 ? cell : '';
            td.contentEditable = cell === 0;
            
            td.addEventListener('input', function() {
                const value = td.textContent.trim(); 
                if (value === '' || (value.length === 1 && /^[1-9]$/.test(value))) {
                    highlightErrors(board, rowIndex, colIndex, value ? parseInt(value) : 0);
                } else {
                    td.textContent = ''; 
                }
            });

            td.addEventListener('keydown', function(event) {
                if (event.key === 'Enter') {
                    event.preventDefault();
                } else if (event.key === 'ArrowUp' && rowIndex > 0) {
                    boardElement.rows[rowIndex - 1].cells[colIndex].focus();
                } else if (event.key === 'ArrowDown' && rowIndex < 8) {
                    boardElement.rows[rowIndex + 1].cells[colIndex].focus();
                } else if (event.key === 'ArrowLeft' && colIndex > 0) {
                    boardElement.rows[rowIndex].cells[colIndex - 1].focus();
                } else if (event.key === 'ArrowRight' && colIndex < 8) {
                    boardElement.rows[rowIndex].cells[colIndex + 1].focus();
                }
            });

            tr.appendChild(td);
        });
        boardElement.appendChild(tr);
    });
}

function highlightErrors(board, rowIndex, colIndex, value) {
    const inputs = document.querySelectorAll('#sudoku td');
    const errorCells = new Set(); 

    inputs.forEach(td => {
        td.style.backgroundColor = '';
        td.classList.remove('pulse-animation'); 
    });

    for (let col = 0; col < N; col++) {
        if (value !== 0 && board[rowIndex][col] === value && col !== colIndex) {
            errorCells.add(boardElement.rows[rowIndex].cells[col]);
        }
    }

    for (let row = 0; row < N; row++) {
        if (value !== 0 && board[row][colIndex] === value && row !== rowIndex) {
            errorCells.add(boardElement.rows[row].cells[colIndex]);
        }
    }

    const startRow = rowIndex - (rowIndex % 3);
    const startCol = colIndex - (colIndex % 3);
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            const row = startRow + i;
            const col = startCol + j;
            if (value !== 0 && board[row][col] === value && (row !== rowIndex || col !== colIndex)) {
                errorCells.add(boardElement.rows[row].cells[col]);
            }
        }
    }

    errorCells.forEach(cell => {
        cell.style.backgroundColor = '#ffcccc'; 
        cell.classList.add('pulse-animation');
    });
}

const style = document.createElement('style');
style.textContent = `
    .pulse-animation {
        animation: pulse 1.5s infinite;
    }
    @keyframes pulse {
        0% { background-color: rgb(200, 70, 70); } 
        50% { background-color: rgb(220, 90, 90); } 
        100% { background-color: rgb(200, 70, 70); }
    }
`;
document.head.appendChild(style);

document.getElementById('Reset').addEventListener('click', generateNewBoard);
document.getElementById('Fill').addEventListener('click', function() {
    const board = Array.from(boardElement.rows).map(row => Array.from(row.cells).map(cell => parseInt(cell.textContent) || 0));
    if (fullFill(board)) {
        displayBoard(board);
    } else {
        alert('Не удалось заполнить Судоку');
    }
});

generateNewBoard();