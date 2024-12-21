package repository;

import model.TodoList;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class TodoListRepositoryImpl implements TodoListRepository {
    private static final String FILE_NAME = "todolist.txt";
    public TodoList[] data = new TodoList[10];

    public TodoListRepositoryImpl() {
        loadFromFile(); // Load data saat repository dibuat
    }

    @Override
    public TodoList[] getAll() {
        return data;
    }

    public boolean isFull() {
        var isFull = true;
        for (int i = 0; i < data.length; i++) {
            if (data[i] == null) {
                isFull = false;
                break;
            }
        }
        return isFull;
    }

    public void resizeIfFull() {
        if (isFull()) {
            var temp = data;
            data = new TodoList[data.length * 2];

            for (int i = 0; i < temp.length; i++) {
                data[i] = temp[i];
            }
        }
    }

    @Override
    public void add(TodoList todolist) {
        resizeIfFull();

        for (var i = 0; i < data.length; i++) {
            if (data[i] == null) {
                data[i] = todolist;
                saveToFile(); // Simpan perubahan ke file
                break;
            }
        }
    }

    @Override
    public boolean remove(Integer number) {
        if ((number - 1) >= data.length) {
            return false;
        } else if (data[number - 1] == null) {
            return false;
        } else {
            for (int i = (number - 1); i < data.length; i++) {
                if (i == (data.length - 1)) {
                    data[i] = null;
                } else {
                    data[i] = data[i + 1];
                }
            }
            saveToFile(); // Simpan perubahan ke file
            return true;
        }
    }

    @Override
    public boolean update(Integer number, TodoList todolist) {
        if ((number - 1) >= data.length) {
            return false;
        } else if (data[number - 1] == null) {
            return false;
        } else {
            for (int i = 0; i < data.length; i++) {
                if (i == (number - 1)) {
                    data[i] = todolist;
                    saveToFile(); // Simpan perubahan ke file
                    return true;
                }
            }
            return false;
        }
    }

    // Method untuk menyimpan data ke file
    private void saveToFile() {
        File file = new File(FILE_NAME);
        try {
            // Buat file jika belum ada
            if (!file.exists()) {
                file.createNewFile();
            }

            // Tulis data ke file
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
                for (TodoList todo : data) {
                    if (todo != null) {
                        writer.write(todo.getTodo());
                        writer.newLine();
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    // Method untuk memuat data dari file
    private void loadFromFile() {
        File file = new File(FILE_NAME);
        if (!file.exists()) {
            // Jika file belum ada, buat file kosong
            try {
                file.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return; // Tidak ada data untuk dimuat
        }

        List<TodoList> todos = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = reader.readLine()) != null) {
                todos.add(new TodoList(line));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Transfer data dari List ke array
        data = new TodoList[todos.size() * 2]; // Beri ruang lebih
        for (int i = 0; i < todos.size(); i++) {
            data[i] = todos.get(i);
        }
    }
}
