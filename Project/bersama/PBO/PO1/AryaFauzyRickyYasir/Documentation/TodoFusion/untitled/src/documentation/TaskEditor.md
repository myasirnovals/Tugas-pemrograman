# Dokumentasi TaskEditor.java

## Deskripsi Umum
`TaskEditor.java` adalah kelas yang menangani pembuatan dan pengeditan tugas dalam aplikasi TodoList. Kelas ini menyediakan antarmuka pengguna untuk memasukkan atau mengubah detail tugas.

## Komponen Utama

### 1. Atribut Kelas
```java
// UI Components
private EditText titleEdit, descriptionEdit;
private TextView dueDateText;
private CheckBox priorityCheck;
private RadioGroup statusGroup;
private RadioButton activeRadio, doneRadio, delayedRadio;
private Button saveButton, deleteButton;

// Data & Utilities
private Database database;
private String mode;
private String currentDate;
private int taskId;
private LocalDate selectedDueDate;
private DateTimeFormatter dateFormatter;
```

### 2. Inisialisasi (onCreate)
```java
@RequiresApi(api = Build.VERSION_CODES.O)
@Override
protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_task_editor);
    
    initializeViews();
    database = new Database(this);
    dateFormatter = DateTimeFormatter.ofPattern("E dd, LLL yyyy", Locale.UK);
    
    // Setup berdasarkan mode (add/edit)
    mode = getIntent().getStringExtra("mode");
    currentDate = getIntent().getStringExtra("date");
}
```

### 3. Fitur-fitur Utama

#### 3.1. Date Picker
```java
private void setupDueDatePicker() {
    dueDateText.setOnClickListener(v -> {
        Calendar calendar = Calendar.getInstance();
        DatePickerDialog datePickerDialog = new DatePickerDialog(
                TaskEditor.this,
                (view, year, month, dayOfMonth) -> {
                    selectedDueDate = LocalDate.of(year, month + 1, dayOfMonth);
                    dueDateText.setText(selectedDueDate.format(dateFormatter));
                },
                calendar.get(Calendar.YEAR),
                calendar.get(Calendar.MONTH),
                calendar.get(Calendar.DAY_OF_MONTH)
        );
        datePickerDialog.show();
    });
}
```

#### 3.2. Penyimpanan Task
```java
private void saveTask() {
    if (!validateInput()) {
        return;
    }

    Task task = new Task();
    // Set task properties
    task.setTitle(titleEdit.getText().toString().trim());
    task.setDescription(descriptionEdit.getText().toString().trim());
    task.setPriority(priorityCheck.isChecked());
    task.setDueDate(selectedDueDate);
    
    // Save to database
    boolean success;
    if (mode.equals("add")) {
        success = database.insertTask(currentDate, task);
    } else {
        success = database.updateTask(currentDate, task);
    }
}
```

#### 3.3. Validasi Input
```java
private boolean validateInput() {
    if (titleEdit.getText().toString().trim().isEmpty()) {
        titleEdit.setError("Title cannot be empty");
        return false;
    }
    if (selectedDueDate == null) {
        dueDateText.setError("Due date must be selected");
        return false;
    }
    if (statusGroup.getCheckedRadioButtonId() == -1) {
        Toast.makeText(this, "Please select a status", Toast.LENGTH_SHORT).show();
        return false;
    }
    return true;
}
```

### 4. Mode Operasi

#### 4.1. Mode Tambah
- Tombol delete disembunyikan
- Form kosong untuk input baru

#### 4.2. Mode Edit
```java
private void loadTaskData() {
    Task task = database.readTask(currentDate, taskId);
    if (task != null) {
        titleEdit.setText(task.getTitle());
        descriptionEdit.setText(task.getDescription());
        priorityCheck.setChecked(task.isPriority());
        selectedDueDate = task.getDueDate();
        dueDateText.setText(task.getDueDateToString());
        // Set status radio button
    }
}
```

### 5. Dialog Konfirmasi

#### 5.1. Konfirmasi Hapus
```java
new AlertDialog.Builder(TaskEditor.this)
    .setTitle("Delete Task")
    .setMessage("Are you sure you want to delete this task?")
    .setPositiveButton("Yes", (dialog, which) -> {
        database.deleteTask(currentDate, taskId);
        setResult(RESULT_OK);
        finish();
    })
    .setNegativeButton("No", null)
    .show();
```

#### 5.2. Konfirmasi Simpan
```java
private void showSaveConfirmation() {
    new AlertDialog.Builder(this)
        .setTitle("Save Task")
        .setMessage("Are you sure you want to save this task?")
        .setPositiveButton("Yes", (dialog, which) -> saveTask())
        .setNegativeButton("No", null)
        .show();
}
```

### 6. Fitur Keamanan

1. **Validasi Input**
    - Judul tidak boleh kosong
    - Tanggal harus dipilih
    - Status harus dipilih

2. **Penanganan Versi Android**
    - Menggunakan @RequiresApi untuk fitur yang membutuhkan API level tertentu
    - Kompatibilitas dengan LocalDate

3. **Konfirmasi Aksi**
    - Dialog konfirmasi untuk hapus
    - Dialog konfirmasi untuk simpan

### 7. Best Practices

1. **Pemisahan Concerns**
    - Metode terpisah untuk inisialisasi
    - Metode terpisah untuk validasi
    - Metode terpisah untuk penyimpanan

2. **User Experience**
    - Pesan error yang jelas
    - Dialog konfirmasi untuk aksi penting
    - Toast untuk feedback

3. **Kode yang Bersih**
    - Penamaan variabel yang jelas
    - Struktur kode yang terorganisir
    - Penanganan error yang baik

Apakah Anda membutuhkan penjelasan lebih detail tentang bagian tertentu dari TaskEditor ini?