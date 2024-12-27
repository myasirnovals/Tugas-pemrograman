package org.kelompok3.todolistapp;

import android.os.Build;

import androidx.annotation.RequiresApi;

import org.threeten.bp.LocalDate;
import org.threeten.bp.format.DateTimeFormatter;
import java.util.Locale;

@RequiresApi(api = Build.VERSION_CODES.O)
public class Task {
    private int ID;
    private String title;
    private String description;
    private boolean priority;
    private String status;
    private LocalDate dueDate;
    private final DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern("E dd, LLL yyyy", Locale.UK);

    public Task() {
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public boolean isPriority() {
        return priority;
    }

    public void setPriority(boolean priority) {
        this.priority = priority;
    }

    public LocalDate getDueDate() {
        return dueDate;
    }

    public void setDueDate(LocalDate dueDate) {
        this.dueDate = dueDate;
    }

    public String getDueDateToString() {
        return dateFormatter.format(dueDate);
    }

    public void setDueDate(String dueDate) {
        this.dueDate = LocalDate.parse(dueDate, dateFormatter);
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }
}
