typedef struct Node{
  int data;
  struct Node *next;
} Node;
Node *head = NULL; 
Node *createNode(int value){

  Node *newNode =(Node*)malloc(sizeof(Node));
  
  if(newNode == NULL){
     printf("Unable to allocate memory.\n");
    return NULL;
  }
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

void addNode(int value){
  
  Node *newNode = createNode(value);
  if (newNode == NULL) return;

  if (head == NULL) {
      head = newNode;
  } else {
      Node *temp = head;
      while (temp->next != NULL) {
          temp = temp->next;
      }
      temp->next = newNode;
  }
}

void RemoveNode(int value){
  Node **currentNode = &head;

  while (*currentNode != NULL) {
      if ((*currentNode)->data == value) {
          Node *temp = *currentNode;
          *currentNode = (*currentNode)->next;
          free(temp);
          printf("Node with value %d removed.\n", value);
          return;
      } else {
          currentNode = &((*currentNode)->next);
      }
  }

  printf("Value %d not found in the list.\n", value);
}

void DisplayList(){

Node *temp = head;
if (temp == NULL) {
    printf("List is empty.\n");
    return;
}
  printf("Linked List: ");
  while (temp != NULL) {
      printf("%d -> ", temp->data);
      temp = temp->next;
  }
}
int main(void) {
  
  Node *head = NULL;
  int choice,value;
  
  while(1){
  printf("\n--- MENU ---\n");
  printf("1. Add Node\n");
  printf("2. Remove Node\n");
  printf("3. Display List\n");
  printf("4. Exit\n");
  printf("Enter your choice: ");
    scanf("%d", &choice);


    switch(choice){
      case 1:
        printf("Enter value to add: ");
        scanf("%d", &value);
        addNode(value);
        break;
      case 2:
        printf("Enter value to remove: ");
        scanf("%d", &value);
        RemoveNode(value);
        break;
      case 3:
        DisplayList();
        break;  
      case 4:
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    
  }
  }
  return 0;
}
