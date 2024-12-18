package repository;

import model.TodoList;

public interface TodoListRepository {
    TodoList[] getAll();

    void add(TodoList todolist);

    boolean remove(Integer number);

    boolean update(Integer number, TodoList todoList);
}
