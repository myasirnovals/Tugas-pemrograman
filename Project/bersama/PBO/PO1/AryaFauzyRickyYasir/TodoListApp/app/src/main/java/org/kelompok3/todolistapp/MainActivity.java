package org.kelompok3.todolistapp;

import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;
import android.app.AlertDialog;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;
import androidx.annotation.NonNull;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.core.content.ContextCompat;

import org.threeten.bp.LocalDate;
import org.threeten.bp.format.DateTimeFormatter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

public class MainActivity extends AppCompatActivity {
    private TextView date;
    private RecyclerView tasks_list;
    private Switch done_tasks;
    private LocalDate liveDate;
    private DateTimeFormatter shortDate;
    private DateTimeFormatter displayDate;
    private Database database;
    private ArrayList<Task> tasksList;
    private TaskAdapter adapter;

    public String getCurrentDate() {
        return shortDate.format(liveDate);
    }

    @RequiresApi(api = Build.VERSION_CODES.O)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        date = findViewById(R.id.date);
        tasks_list = findViewById(R.id.tasks_list);
        tasks_list.setLayoutManager(new LinearLayoutManager(this));
        done_tasks = findViewById(R.id.done_tasks);

        LinearLayout add = findViewById(R.id.add);

        shortDate = DateTimeFormatter.ofPattern("yyyy-MM-dd", Locale.UK);
        displayDate = DateTimeFormatter.ofPattern("E dd, LLL yyyy", Locale.UK);
        liveDate = LocalDate.now();

        database = new Database(this);
        database.createDatabase(shortDate.format(liveDate));

        date.setText(liveDate.format(displayDate));

        add.setOnClickListener(view -> {
            Intent intent = new Intent(MainActivity.this, TaskEditor.class);
            intent.putExtra("date", shortDate.format(liveDate));
            intent.putExtra("mode", "add");
            startActivityForResult(intent, 1);
        });

        done_tasks.setOnCheckedChangeListener((buttonView, isChecked) -> loadTasks());

        loadTasks();
    }

    @RequiresApi(api = Build.VERSION_CODES.O)
    @Override
    protected void onResume() {
        super.onResume();
        loadTasks();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (resultCode == RESULT_OK) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                loadTasks();
            }
            Toast.makeText(this, "Task updated successfully", Toast.LENGTH_SHORT).show();
        }
    }


    @RequiresApi(api = Build.VERSION_CODES.O)
    private void loadTasks() {
        try {
            tasksList = database.getTasks(shortDate.format(liveDate));
            if (!done_tasks.isChecked()) {
                ArrayList<Task> activeTasks = new ArrayList<>();
                for (Task task : tasksList) {
                    if (task != null && task.getStatus() != null && !task.getStatus().equals("Done")) {
                        activeTasks.add(task);
                    }
                }
                tasksList = activeTasks;
            }

            if (tasksList == null) {
                tasksList = new ArrayList<>();
            }

            adapter = new TaskAdapter(this, tasksList);
            tasks_list.setAdapter(adapter);

            setupSwipeToDelete();
        } catch (Exception e) {
            e.printStackTrace();
            Toast.makeText(this, "Terjadi kesalahan saat memuat data", Toast.LENGTH_SHORT).show();
        }
    }

    private void setupSwipeToDelete() {
        ItemTouchHelper.SimpleCallback swipeCallback = new ItemTouchHelper.SimpleCallback(0, ItemTouchHelper.LEFT) {
            @Override
            public boolean onMove(@NonNull RecyclerView recyclerView, @NonNull RecyclerView.ViewHolder viewHolder, @NonNull RecyclerView.ViewHolder target) {
                return false;
            }

            @Override
            public void onSwiped(@NonNull RecyclerView.ViewHolder viewHolder, int direction) {
                int position = viewHolder.getAdapterPosition();
                Task taskToDelete = tasksList.get(position);

                new AlertDialog.Builder(MainActivity.this)
                        .setTitle("Hapus Task")
                        .setMessage("Apakah Anda yakin ingin menghapus task ini?")
                        .setPositiveButton("Ya", (dialog, which) -> {
                            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                                database.deleteTask(shortDate.format(liveDate), taskToDelete.getID());
                                tasksList.remove(position);
                                adapter.notifyItemRemoved(position);
                                loadTasks();
                                Toast.makeText(MainActivity.this, "Task berhasil dihapus", Toast.LENGTH_SHORT).show();
                            }
                        })
                        .setNegativeButton("Tidak", (dialog, which) -> {
                            adapter.notifyItemChanged(position);
                        })
                        .setCancelable(false)
                        .show();
            }

            @Override
            public void onChildDraw(@NonNull Canvas c, @NonNull RecyclerView recyclerView,
                                    @NonNull RecyclerView.ViewHolder viewHolder,
                                    float dX, float dY, int actionState, boolean isCurrentlyActive) {
                View itemView = viewHolder.itemView;
                ColorDrawable background = new ColorDrawable(Color.RED);
                Drawable deleteIcon = ContextCompat.getDrawable(MainActivity.this, R.drawable.ic_delete);

                int iconMargin = (itemView.getHeight() - deleteIcon.getIntrinsicHeight()) / 2;

                background.setBounds(itemView.getRight() + (int) dX, itemView.getTop(),
                        itemView.getRight(), itemView.getBottom());
                background.draw(c);

                if (dX < 0) {
                    deleteIcon.setBounds(itemView.getRight() - iconMargin - deleteIcon.getIntrinsicWidth(),
                            itemView.getTop() + iconMargin,
                            itemView.getRight() - iconMargin,
                            itemView.getBottom() - iconMargin);
                    deleteIcon.draw(c);
                }

                super.onChildDraw(c, recyclerView, viewHolder, dX, dY, actionState, isCurrentlyActive);
            }
        };

        new ItemTouchHelper(swipeCallback).attachToRecyclerView(tasks_list);
    }

    public class ListAdapter extends BaseAdapter {
        private final ArrayList<Task> tasks;

        public ListAdapter(ArrayList<Task> tasks) {
            this.tasks = tasks;
        }

        @Override
        public int getCount() {
            return tasks.size();
        }

        @Override
        public Task getItem(int i) {
            return tasks.get(i);
        }

        @Override
        public long getItemId(int i) {
            return i;
        }

        @RequiresApi(api = Build.VERSION_CODES.O)
        @Override
        public View getView(int i, View view, ViewGroup viewGroup) {
            View v = getLayoutInflater().inflate(R.layout.task_listitem, null);

            LinearLayout parent_layout = v.findViewById(R.id.parent_layout);
            ImageView circle = v.findViewById(R.id.circle);
            TextView task_title = v.findViewById(R.id.task_title);
            TextView task_description = v.findViewById(R.id.task_description);
            TextView status = v.findViewById(R.id.status);
            TextView date = v.findViewById(R.id.date);

            Task task = tasks.get(i);
            task_title.setText(task.getTitle());

            if (task.getDescription() != null && !task.getDescription().isEmpty()) {
                task_description.setVisibility(View.VISIBLE);
                task_description.setText(task.getDescription());
            }

            if (task.getDueDate() != null) {
                date.setText(task.getDueDateToString());
            }

            if (task.getStatus() != null && !task.getStatus().isEmpty()) {
                switch (task.getStatus()) {
                    case "Active":
                        circle.setImageResource(R.drawable.green_circle);
                        status.setBackgroundResource(R.drawable.green_box);
                        status.setText(R.string.aktif);
                        status.setTextColor(getResources().getColor(R.color.green_dark));
                        break;
                    case "Done":
                        circle.setImageResource(R.drawable.blue_circle);
                        status.setBackgroundResource(R.drawable.blue_box);
                        status.setText(R.string.selesai);
                        status.setTextColor(getResources().getColor(R.color.blue_dark));
                        break;
                    case "Delayed":
                        circle.setImageResource(R.drawable.red_circle);
                        status.setBackgroundResource(R.drawable.red_box);
                        status.setText(R.string.tunda);
                        status.setTextColor(getResources().getColor(R.color.red_dark));
                        break;
                    case "None":
                        circle.setImageResource(R.drawable.gray_circle);
                        status.setBackgroundResource(R.drawable.gray_box);
                        status.setText(R.string.none);
                        status.setTextColor(getResources().getColor(R.color.black));
                        break;
                }
            }

            parent_layout.setOnClickListener(view1 -> {
                Intent intent = new Intent(MainActivity.this, TaskEditor.class);
                intent.putExtra("date", shortDate.format(liveDate));
                intent.putExtra("mode", "edit");
                intent.putExtra("taskId", task.getID());
                startActivity(intent);
            });

            notifyDataSetChanged();

            return v;
        }
    }

    @RequiresApi(api = Build.VERSION_CODES.O)
    private void sortTasksByStatus() {
        tasksList.sort((task1, task2) -> {
            Map<String, Integer> statusPriority = new HashMap<>();
            statusPriority.put("Active", 1);
            statusPriority.put("Delayed", 2);
            statusPriority.put("Done", 3);
            statusPriority.put("None", 4);

            String status1 = task1.getStatus();
            String status2 = task2.getStatus();

            return statusPriority.getOrDefault(status1, 5)
                    - statusPriority.getOrDefault(status2, 5);
        });
    }

}
