package org.kelompok3.todolistapp;

import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;
import androidx.annotation.NonNull;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import android.app.AlertDialog;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import androidx.core.content.ContextCompat;

import com.jakewharton.threetenabp.AndroidThreeTen;

import org.threeten.bp.LocalDate;
import org.threeten.bp.format.DateTimeFormatter;

import java.util.ArrayList;
import java.util.Locale;

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

        // Initialize views (hapus line yang duplikat)
        date = findViewById(R.id.date);
        tasks_list = findViewById(R.id.tasks_list);
        tasks_list.setLayoutManager(new LinearLayoutManager(this));
        done_tasks = findViewById(R.id.done_tasks);
        LinearLayout add = findViewById(R.id.add);

        // Initialize date formatters
        shortDate = DateTimeFormatter.ofPattern("yyyy-MM-dd", Locale.UK);
        displayDate = DateTimeFormatter.ofPattern("E dd, LLL yyyy", Locale.UK);
        liveDate = LocalDate.now();

        // Initialize database
        database = new Database(this);
        database.createDatabase(shortDate.format(liveDate));

        // Set current date
        date.setText(liveDate.format(displayDate));

        // Add button click listener
        add.setOnClickListener(view -> {
            Intent intent = new Intent(MainActivity.this, TaskEditor.class);
            intent.putExtra("date", shortDate.format(liveDate));
            intent.putExtra("mode", "add");
            startActivityForResult(intent, 1);
        });

        // Switch listener for showing/hiding done tasks
        done_tasks.setOnCheckedChangeListener((buttonView, isChecked) -> loadTasks());

        // Load initial tasks
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
        tasksList = database.getTasks(shortDate.format(liveDate));
        if (!done_tasks.isChecked()) {
            ArrayList<Task> activeTasks = new ArrayList<>();
            for (Task task : tasksList) {
                if (!task.getStatus().equals("Done")) {
                    activeTasks.add(task);
                }
            }
            tasksList = activeTasks;
        }

        // Ganti bagian ini
        adapter = new TaskAdapter(this, tasksList);
        tasks_list.setAdapter(adapter);

        // Setup swipe-to-delete
        setupSwipeToDelete();
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
                                // Refresh data setelah penghapusan
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

                background.setBounds(itemView.getRight() + (int)dX, itemView.getTop(),
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

            // Set task title
            task_title.setText(task.getTitle());

            // Set task description if exists
            if (task.getDescription() != null && !task.getDescription().isEmpty()) {
                task_description.setVisibility(View.VISIBLE);
                task_description.setText(task.getDescription());
            }

            // Set due date
            if (task.getDueDate() != null) {
                date.setText(task.getDueDateToString());
            }

            // Set status and colors
            if (task.getStatus() != null && !task.getStatus().isEmpty()) {
                switch (task.getStatus()) {
                    case "Active":
                        circle.setImageResource(R.drawable.green_circle);
                        status.setBackgroundResource(R.drawable.green_box);
                        status.setText("Active");
                        status.setTextColor(getResources().getColor(R.color.green_dark));
                        break;
                    case "Done":
                        circle.setImageResource(R.drawable.blue_circle);
                        status.setBackgroundResource(R.drawable.blue_box);
                        status.setText("Done");
                        status.setTextColor(getResources().getColor(R.color.blue_dark));
                        break;
                    case "Delayed":
                        circle.setImageResource(R.drawable.red_circle);
                        status.setBackgroundResource(R.drawable.red_box);
                        status.setText("Delayed");
                        status.setTextColor(getResources().getColor(R.color.red_dark));
                        break;
                }
            }

            // Set click listener for editing
            parent_layout.setOnClickListener(view1 -> {
                Intent intent = new Intent(MainActivity.this, TaskEditor.class);
                intent.putExtra("date", shortDate.format(liveDate));
                intent.putExtra("mode", "edit");
                intent.putExtra("taskId", task.getID());
                startActivity(intent);
            });

            // Tambahkan di akhir method
            notifyDataSetChanged();

            return v;
        }
    }
}
