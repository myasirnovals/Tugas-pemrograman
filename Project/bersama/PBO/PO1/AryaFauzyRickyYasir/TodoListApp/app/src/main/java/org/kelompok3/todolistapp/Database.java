package org.kelompok3.todolistapp;

import android.content.Context;
import android.os.Build;
import android.util.Log;

import androidx.annotation.RequiresApi;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import org.threeten.bp.LocalDate;
import org.threeten.bp.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Locale;

public class Database {
    private Context context;
    private static final String FILE_PREFIX = "tasks_";
    private DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd", Locale.UK);

    public Database(Context context) {
        this.context = context;
    }

    private String getFileName(String date) {
        return FILE_PREFIX + date + ".json";
    }

    public void createDatabase(String date) {
        File file = new File(context.getFilesDir(), getFileName(date));
        if (!file.exists()) {
            try {
                JSONObject jsonObject = new JSONObject();
                jsonObject.put("tasks", new JSONArray());
                FileOutputStream fos = context.openFileOutput(getFileName(date), Context.MODE_PRIVATE);
                fos.write(jsonObject.toString().getBytes());
                fos.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    @RequiresApi(api = Build.VERSION_CODES.O)
    public boolean insertTask(String date, Task task) {
        try {
            JSONObject jsonData = readJsonFile(date);
            JSONArray tasks = jsonData.getJSONArray("tasks");

            // Generate new ID
            int newId = tasks.length() + 1;
            task.setID(newId);

            // Pastikan status tidak null
            if (task.getStatus() == null) {
                task.setStatus("Active"); // Set default status
            }

            // Convert task to JSON
            JSONObject taskJson = new JSONObject();
            taskJson.put("id", task.getID());
            taskJson.put("title", task.getTitle());
            taskJson.put("description", task.getDescription());
            taskJson.put("priority", task.isPriority());
            taskJson.put("status", task.getStatus()); // Pastikan status selalu ada
            taskJson.put("dueDate", task.getDueDate().format(dateFormatter));

            tasks.put(taskJson);
            writeJsonFile(date, jsonData);
            return true;
        } catch (Exception e) {
            Log.e("Database", "Error writing to file: " + e.getMessage());
            return false;
        }
    }

    @RequiresApi(api = Build.VERSION_CODES.O)
    public ArrayList<Task> getTasks(String date) {
        ArrayList<Task> taskList = new ArrayList<>();
        try {
            JSONObject jsonData = readJsonFile(date);
            JSONArray tasks = jsonData.getJSONArray("tasks");

            for (int i = 0; i < tasks.length(); i++) {
                JSONObject taskJson = tasks.getJSONObject(i);
                Task task = new Task();
                task.setID(taskJson.getInt("id"));
                task.setTitle(taskJson.getString("title"));
                task.setDescription(taskJson.optString("description", "")); // Using optString for optional fields
                task.setPriority(taskJson.optBoolean("priority", false));
                task.setStatus(taskJson.optString("status", "Active")); // Default to Active if not present

                String dueDateStr = taskJson.optString("dueDate", null);
                if (dueDateStr != null) {
                    task.setDueDate(LocalDate.parse(dueDateStr, dateFormatter));
                }

                taskList.add(task);
            }
        } catch (Exception e) {
            Log.e("Database", "Error reading tasks: " + e.getMessage());
            e.printStackTrace();
        }
        return taskList;
    }

    @RequiresApi(api = Build.VERSION_CODES.O)
    public Task readTask(String date, int ID) {
        try {
            JSONObject jsonData = readJsonFile(date);
            JSONArray tasks = jsonData.getJSONArray("tasks");

            for (int i = 0; i < tasks.length(); i++) {
                JSONObject taskJson = tasks.getJSONObject(i);
                if (taskJson.getInt("id") == ID) {
                    Task task = new Task();
                    task.setID(taskJson.getInt("id"));
                    task.setTitle(taskJson.getString("title"));
                    task.setDescription(taskJson.getString("description"));
                    task.setPriority(taskJson.getBoolean("priority"));
                    task.setStatus(taskJson.getString("status"));
                    task.setDueDate(LocalDate.parse(taskJson.getString("dueDate"), dateFormatter));
                    return task;
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    @RequiresApi(api = Build.VERSION_CODES.O)
    public boolean updateTask(String date, Task task) {
        try {
            JSONObject jsonData = readJsonFile(date);
            JSONArray tasks = jsonData.getJSONArray("tasks");

            // Find and update the task
            for (int i = 0; i < tasks.length(); i++) {
                JSONObject taskJson = tasks.getJSONObject(i);
                if (taskJson.getInt("id") == task.getID()) {
                    // Update task data
                    taskJson.put("title", task.getTitle());
                    taskJson.put("description", task.getDescription());
                    taskJson.put("priority", task.isPriority());
                    taskJson.put("status", task.getStatus());
                    taskJson.put("dueDate", task.getDueDate().format(dateFormatter));

                    // Write back to file
                    writeJsonFile(date, jsonData);
                    return true;
                }
            }
            return false; // Task not found
        } catch (Exception e) {
            Log.e("Database", "Error updating task: " + e.getMessage());
            e.printStackTrace();
            return false;
        }
    }


    public void deleteTask(String date, int ID) {
        try {
            JSONObject jsonData = readJsonFile(date);
            JSONArray tasks = jsonData.getJSONArray("tasks");
            JSONArray newTasks = new JSONArray();

            for (int i = 0; i < tasks.length(); i++) {
                JSONObject taskJson = tasks.getJSONObject(i);
                if (taskJson.getInt("id") != ID) {
                    newTasks.put(taskJson);
                }
            }

            jsonData.put("tasks", newTasks);
            writeJsonFile(date, jsonData);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private JSONObject readJsonFile(String date) throws IOException, JSONException {
        FileInputStream fis = context.openFileInput(getFileName(date));
        byte[] data = new byte[fis.available()];
        fis.read(data);
        fis.close();
        return new JSONObject(new String(data));
    }

    private void writeJsonFile(String date, JSONObject jsonData) throws IOException {
        FileOutputStream fos = context.openFileOutput(getFileName(date), Context.MODE_PRIVATE);
        fos.write(jsonData.toString().getBytes());
        fos.close();
    }
}
