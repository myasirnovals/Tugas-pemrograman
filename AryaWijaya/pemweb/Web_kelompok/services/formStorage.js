const dataCollection = [];
const RENDER_EVENT = 'render-data';
const SAVED_EVENT = 'saved-data';
const STORAGE_KEY = 'DATA_FORM';

function generateId() {
    return Math.random().toString(16).slice(2);
}

function generateDataObject(id, name, nim, address, hobby) {
    return {
        id, name, nim, address, hobby
    };
}

function addData() {
    const dataName = document.getElementById('name').value;
    const dataNim = document.getElementById('nim').value;
    const dataAddress = document.getElementById('address').value;
    const dataHobby = document.getElementById('hobby').value;

    const generatedID = generateId();
    const dataObject = generateDataObject(generatedID, dataName, dataNim, dataAddress, dataHobby);
    dataCollection.push(dataObject);
    document.dispatchEvent(new Event(RENDER_EVENT));
    saveData();
}

function saveData() {
    if (isStorageExist()) {
        const parsed = JSON.stringify(dataCollection);
        sessionStorage.setItem(STORAGE_KEY, parsed);
        document.dispatchEvent(new Event(SAVED_EVENT));
    }
}

function isStorageExist() { // return boolean value
    if (typeof (Storage) === undefined) {
        alert('Browser kamu tidak mendukung local storage');
        return false;
    }

    return true;
}

function loadDataFromStorage() {
    const serializedData = sessionStorage.getItem(STORAGE_KEY);
    let data = JSON.parse(serializedData);

    if (data !== null) {
        for (const listData of data) {
            dataCollection.push(listData);
        }
    }

    document.dispatchEvent(new Event(RENDER_EVENT));
}

document.addEventListener('DOMContentLoaded', function () {
    const submitForm /* HTMLFormElement */ = document.getElementById('form');

    submitForm.addEventListener('submit', function (event) {
        event.preventDefault();
        addData();
    });

    if (isStorageExist()) {
        loadDataFromStorage();
    }
});

document.addEventListener(SAVED_EVENT, function () {
    console.log(sessionStorage.getItem(STORAGE_KEY));
    alert('data berhasil ditambahkan');
});