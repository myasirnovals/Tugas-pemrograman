package org.kelompok3.todolistapp;

import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.RequiresApi;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class TaskAdapter extends RecyclerView.Adapter<TaskAdapter.TaskViewHolder> {
    private final ArrayList<Task> tasks;
    private final Context context;

    public TaskAdapter(Context context, ArrayList<Task> tasks) {
        this.context = context;
        this.tasks = tasks;
    }

    @NonNull
    @Override
    public TaskViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.task_listitem, parent, false);
        return new TaskViewHolder(view);
    }

    @RequiresApi(api = Build.VERSION_CODES.O)
    @Override
    public void onBindViewHolder(@NonNull TaskViewHolder holder, int position) {
        Task task = tasks.get(position);
        holder.task_title.setText(task.getTitle());

        if (task.getDescription() != null && !task.getDescription().isEmpty()) {
            holder.task_description.setVisibility(View.VISIBLE);
            holder.task_description.setText(task.getDescription());
        }

        if (task.getDueDate() != null) {
            holder.date.setText(task.getDueDateToString());
        }

        if (task.getStatus() != null && !task.getStatus().isEmpty()) {
            switch (task.getStatus()) {
                case "Active":
                    holder.circle.setImageResource(R.drawable.green_circle);
                    holder.status.setBackgroundResource(R.drawable.green_box);
                    holder.status.setText(R.string.aktif);
                    holder.status.setTextColor(context.getResources().getColor(R.color.green_dark));
                    break;
                case "Done":
                    holder.circle.setImageResource(R.drawable.blue_circle);
                    holder.status.setBackgroundResource(R.drawable.blue_box);
                    holder.status.setText(R.string.selesai);
                    holder.status.setTextColor(context.getResources().getColor(R.color.blue_dark));
                    break;
                case "Delayed":
                    holder.circle.setImageResource(R.drawable.red_circle);
                    holder.status.setBackgroundResource(R.drawable.red_box);
                    holder.status.setText(R.string.tunda);
                    holder.status.setTextColor(context.getResources().getColor(R.color.red_dark));
                    break;
                case "None":
                    holder.circle.setImageResource(R.drawable.gray_circle);
                    holder.status.setBackgroundResource(R.drawable.gray_box);
                    holder.status.setText(R.string.none);
                    holder.status.setTextColor(context.getResources().getColor(R.color.black));
                    break;
            }
        }

        holder.parent_layout.setOnClickListener(v -> {
            Intent intent = new Intent(context, TaskEditor.class);
            intent.putExtra("date", ((MainActivity)context).getCurrentDate());
            intent.putExtra("mode", "edit");
            intent.putExtra("taskId", task.getID());
            context.startActivity(intent);
        });
    }

    @Override
    public int getItemCount() {
        return tasks.size();
    }

    static class TaskViewHolder extends RecyclerView.ViewHolder {
        LinearLayout parent_layout;
        ImageView circle;
        TextView task_title, task_description, status, date;

        TaskViewHolder(@NonNull View itemView) {
            super(itemView);
            parent_layout = itemView.findViewById(R.id.parent_layout);
            circle = itemView.findViewById(R.id.circle);
            task_title = itemView.findViewById(R.id.task_title);
            task_description = itemView.findViewById(R.id.task_description);
            status = itemView.findViewById(R.id.status);
            date = itemView.findViewById(R.id.date);
        }
    }
}

