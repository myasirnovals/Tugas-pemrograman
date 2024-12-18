package service;

import model.TodoList;
import repository.TodoListRepository;

public class TodoListServiceImpl implements TodoListService {
    private TodoListRepository todoListRepository;

    public TodoListServiceImpl(TodoListRepository todoListRepository) {
        this.todoListRepository = todoListRepository;
    }

    @Override
    public void showTodoList() {
        TodoList[] model = todoListRepository.getAll();

        System.out.println("TODOLIST");
        for (var i = 0; i < model.length; i++) {
            var todolist = model[i];
            var no = i + 1;

            if (todolist != null) {
                System.out.println(no + ". " + todolist.getTodo());
            }
        }
    }

    @Override
    public void addTodoList(String todo) {
        TodoList todolist = new TodoList(todo);
        todoListRepository.add(todolist);
        System.out.println("Success");
    }

    @Override
    public void removeTodoList(Integer number) {
        boolean success = todoListRepository.remove(number);

        if(success) {
            System.out.println("Success delete todo : " + number);
        } else {
            System.out.println("Fail delete todo : " + number);
        }
    }

    @Override
    public void updateTodoList(Integer number, String todo) {
        TodoList todoList = new TodoList(todo);
        boolean success = todoListRepository.update(number, todoList);

        if(success) {
            System.out.println("Success edit todo : " + number);
        } else {
            System.out.println("Fail edit todo : " + number);
        }
    }
}
