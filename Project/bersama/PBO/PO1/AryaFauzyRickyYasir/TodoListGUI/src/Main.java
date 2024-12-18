import service.*;
import repository.*;
import view.*;


public class Main {
     public static void main(String[] args) {
       TodoListRepository todoListRepository = new TodoListRepositoryImpl();
        TodoListService todoListService = new TodoListServiceImpl(todoListRepository);
        TodoListView todoListView = new TodoListView(todoListService);

        todoListView.showTodoList();
    }
}