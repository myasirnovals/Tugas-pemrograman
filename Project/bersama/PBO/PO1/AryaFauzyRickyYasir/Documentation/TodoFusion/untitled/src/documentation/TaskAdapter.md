# Dokumentasi TaskAdapter.java

## Deskripsi Umum
`TaskAdapter.java` adalah kelas adapter yang menghubungkan data tugas (Task) dengan tampilan RecyclerView. Kelas ini mengatur bagaimana setiap item tugas ditampilkan dalam daftar.

## Struktur Kelas

### 1. Properti Utama
```java
private final ArrayList<Task> tasks;  // Daftar tugas
private final Context context;        // Context aplikasi
```

### 2. Konstruktor
```java
public TaskAdapter(Context context, ArrayList<Task> tasks) {
    this.context = context;
    this.tasks = tasks;
}
```

### 3. ViewHolder
```java
static class TaskViewHolder extends RecyclerView.ViewHolder {
    LinearLayout parent_layout;
    ImageView circle;
    TextView task_title, task_description, status, date;
    
    // Inisialisasi komponen UI
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
```

### 4. Metode Override RecyclerView.Adapter

#### 4.1. onCreateViewHolder()
```java
@Override
public TaskViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
    View view = LayoutInflater.from(context).inflate(R.layout.task_listitem, parent, false);
    return new TaskViewHolder(view);
}
```
- Membuat tampilan baru untuk item tugas
- Menggunakan layout `task_listitem.xml`

#### 4.2. onBindViewHolder()
```java
@RequiresApi(api = Build.VERSION_CODES.O)
@Override
public void onBindViewHolder(@NonNull TaskViewHolder holder, int position) {
    Task task = tasks.get(position);
    // Set data ke tampilan
}
```

### 5. Fitur Tampilan

#### 5.1. Status Tugas dengan Warna
```java
switch (task.getStatus()) {
    case "Active":
        // Warna hijau untuk tugas aktif
        holder.circle.setImageResource(R.drawable.green_circle);
        holder.status.setBackgroundResource(R.drawable.green_box);
        holder.status.setTextColor(context.getResources().getColor(R.color.green_dark));
        break;
    case "Done":
        // Warna biru untuk tugas selesai
        holder.circle.setImageResource(R.drawable.blue_circle);
        holder.status.setBackgroundResource(R.drawable.blue_box);
        holder.status.setTextColor(context.getResources().getColor(R.color.blue_dark));
        break;
    case "Delayed":
        // Warna merah untuk tugas terlambat
        holder.circle.setImageResource(R.drawable.red_circle);
        holder.status.setBackgroundResource(R.drawable.red_box);
        holder.status.setTextColor(context.getResources().getColor(R.color.red_dark));
        break;
}
```

#### 5.2. Penanganan Deskripsi Opsional
```java
if (task.getDescription() != null && !task.getDescription().isEmpty()) {
    holder.task_description.setVisibility(View.VISIBLE);
    holder.task_description.setText(task.getDescription());
}
```

#### 5.3. Penanganan Tanggal
```java
if (task.getDueDate() != null) {
    holder.date.setText(task.getDueDateToString());
}
```

### 6. Interaksi Pengguna

#### 6.1. Click Listener
```java
holder.parent_layout.setOnClickListener(v -> {
    Intent intent = new Intent(context, TaskEditor.class);
    intent.putExtra("date", ((MainActivity)context).getCurrentDate());
    intent.putExtra("mode", "edit");
    intent.putExtra("taskId", task.getID());
    context.startActivity(intent);
});
```
- Membuka TaskEditor saat item diklik
- Mode edit dengan ID tugas yang dipilih

### 7. Penggunaan

```java
// Membuat adapter
ArrayList<Task> taskList = new ArrayList<>();
TaskAdapter adapter = new TaskAdapter(context, taskList);

// Set adapter ke RecyclerView
RecyclerView recyclerView = findViewById(R.id.recycler_view);
recyclerView.setAdapter(adapter);
```

### 8. Fitur Utama

1. **Tampilan Dinamis**
    - Menampilkan/menyembunyikan deskripsi
    - Warna berbeda untuk setiap status
    - Format tanggal yang konsisten

2. **Interaktivitas**
    - Click listener untuk edit tugas
    - Navigasi ke TaskEditor

3. **Visual Feedback**
    - Indikator status dengan warna
    - Layout yang rapi dan terstruktur

### 9. Best Practices

1. **View Recycling**
    - Menggunakan ViewHolder pattern
    - Efisien dalam penggunaan memori

2. **Null Safety**
    - Pengecekan null untuk deskripsi
    - Pengecekan null untuk tanggal
    - Pengecekan null untuk status

3. **Clean Code**
    - Pemisahan logic dalam metode yang berbeda
    - Penggunaan konstanta untuk status
    - Kode yang mudah dibaca dan dipelihara

Apakah Anda membutuhkan penjelasan lebih detail tentang bagian tertentu dari TaskAdapter ini?