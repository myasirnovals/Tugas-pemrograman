import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import model.TodoList;
import service.TodoListService;
import service.TodoListServiceImpl;
import repository.TodoListRepository;
import repository.TodoListRepositoryImpl;

public class Main {
    private JFrame frame;
    private DefaultListModel<String> listModel;
    private JList<String> todoList;
    private TodoListService todoListService;

    public Main(TodoListService todoListService) {
        this.todoListService = todoListService;
        initialize();
    }

    private void initialize() {
        // Frame setup
        frame = new JFrame("To-Do List Application");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 500);

        // Panel for content
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());

        // List model and JList
        listModel = new DefaultListModel<>();
        todoList = new JList<>(listModel);
        JScrollPane scrollPane = new JScrollPane(todoList);

        // Load initial data
        refreshTodoList(); // Muat data dari backend ke GUI

        // Buttons
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new FlowLayout());

        JButton addButton = new JButton("Add");
        JButton editButton = new JButton("Edit");
        JButton deleteButton = new JButton("Delete");

        // Add button actions
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String todo = JOptionPane.showInputDialog(frame, "Enter new to-do:");
                if (todo != null && !todo.trim().isEmpty()) {
                    todoListService.addTodoList(todo);
                    refreshTodoList();
                }
            }
        });

        editButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectedIndex = todoList.getSelectedIndex();
                if (selectedIndex != -1) {
                    String updatedTodo = JOptionPane.showInputDialog(frame, "Edit to-do:", listModel.get(selectedIndex));
                    if (updatedTodo != null && !updatedTodo.trim().isEmpty()) {
                        todoListService.updateTodoList(selectedIndex + 1, updatedTodo);
                        refreshTodoList();
                    }
                } else {
                    JOptionPane.showMessageDialog(frame, "Please select a to-do to edit.");
                }
            }
        });

        deleteButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectedIndex = todoList.getSelectedIndex();
                if (selectedIndex != -1) {
                    todoListService.removeTodoList(selectedIndex + 1);
                    refreshTodoList();
                } else {
                    JOptionPane.showMessageDialog(frame, "Please select a to-do to delete.");
                }
            }
        });

        // Add components to panel
        buttonPanel.add(addButton);
        buttonPanel.add(editButton);
        buttonPanel.add(deleteButton);

        panel.add(scrollPane, BorderLayout.CENTER);
        panel.add(buttonPanel, BorderLayout.SOUTH);

        frame.getContentPane().add(panel);
        frame.setVisible(true);
    }


    private void loadTodoList() {
        listModel.clear();
        TodoList[] todos = todoListService.showTodoListForGUI();
        for (TodoList todo : todos) {
            if (todo != null) {
                listModel.addElement(todo.getTodo());
            }
        }
    }

    private void refreshTodoList() {
        listModel.clear();
        TodoList[] todos = todoListService.showTodoListForGUI();
        for (TodoList todo: todos) {
            if (todo != null) {
                listModel.addElement(todo.getTodo());
            }
        }
    }

    public static void main(String[] args) {
        TodoListRepository repository = new TodoListRepositoryImpl();
        TodoListService service = new TodoListServiceImpl(repository);
        new Main(service);
    }
}