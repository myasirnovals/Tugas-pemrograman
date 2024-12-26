package repository;

import model.TodoList;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class TodoListRepositoryImpl implements TodoListRepository {
    private static final String FILE_NAME = "H:/OneDrive/Documents/Tugas-pemrograman/Project/bersama/PBO/PO1/AryaFauzyRickyYasir/TodoListGUI/todolist.txt";
    public TodoList[] data = new TodoList[10];

    public TodoListRepositoryImpl() {
        loadFromFile(); // Load data saat repository dibuat
    }

    @Override
    public TodoList[] getAll() {
        List<TodoList> todos = new ArrayList<>();
        for (TodoList todo : data) {
            if (todo != null) {
                System.out.println("Data ditemukan di array: " + todo.getTodo()); // Log untuk debugging
                todos.add(todo);
            }
        }
        System.out.println("Total data di array: " + todos.size());
        return todos.toArray(new TodoList[0]);
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
                System.out.println("Menambahkan data ke array: " + todolist.getTodo()); // Log untuk debugging
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
            if (!file.exists()) {
                file.createNewFile(); // Buat file jika belum ada
            }

            try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
                for (TodoList todo : data) {
                    if (todo != null) {
                        writer.write(todo.getTodo());
                        writer.newLine();
                        System.out.println("Data disimpan ke file: " + todo.getTodo()); // Log data yang disimpan
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
        System.out.println("Mencari file di lokasi: " + file.getAbsolutePath()); // Log lokasi file
        if (!file.exists()) {
            try {
                file.createNewFile(); // Buat file jika belum ada
                System.out.println("File tidak ditemukan, membuat file baru.");
            } catch (IOException e) {
                e.printStackTrace();
            }
            return;
        }

        List<TodoList> todos = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println("Data ditemukan di file: " + line); // Log data yang ditemukan
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
        System.out.println("Data berhasil dimuat ke array: " + todos.size() + " item(s)");
    }
}
