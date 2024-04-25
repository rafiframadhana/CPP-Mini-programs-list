#include<iostream>
using namespace std;

struct nod {
   int info;
   struct nod *next;
   struct nod *previous;
}*start, *last;
int count = 0;

class dcll {
   public:
      nod *create_node(int);
      void begin_insert();
      void last_insert();
      void position_insert();
      void position_delete();
      void search();
      void update();
      void display();
      void reverse();
      dcll() {
         start = NULL;
         last = NULL;
      }
};
int main(){
	int c;
	dcll dcll;
    
	cout<<"1.Insert at the Beginning"<<endl;
    cout<<"2.Insert at the End"<<endl;
    cout<<"3.Insert at any Position"<<endl;
    cout<<"4.Delete from any Position"<<endl;
    cout<<"5.Update Element"<<endl;
    cout<<"6.Search an Element"<<endl;
    cout<<"7.Display List"<<endl;
    cout<<"8.Reverse List"<<endl;
    cout<<"9.Exit"<<endl;
      
    do{
      cout<<"\nEnter your choice : ";
      cin>>c;
      switch(c) {
         case 1:
            dcll.begin_insert();
         break;
         case 2:
            dcll.last_insert();
         break;
         case 3:
            dcll.position_insert();
         break;
         case 4:
            dcll.position_delete();
         break;
         case 5:
            dcll.update();
         break;
         case 6:
            dcll.search();
         break;
         case 7:
            dcll.display();
         break;
         case 8:
            dcll.reverse();
         break;
         case 9:
            cout<<"Exit";
            break;
         default:
            cout<<"Invalid choice"<<endl;
            break;
      }
   }while(c!=9);
   return 0;
}


nod* dcll::create_node(int val) {
   count++;
   struct nod *t;
   t = new(struct nod);
   t->info = val;
   t->next = NULL;
   t->previous = NULL;
   return t;
}


void dcll::begin_insert() {
   int val;
   cout<<"Enter value: ";
   cin>>val;
   struct nod *t;
   t = create_node(val);
   if (start == last && start == NULL) {	
      start = last = t;
      start->next = last->next = NULL;
      start->previous = last->previous = NULL;
   } else {
      t->next = start;
      start->previous = t;
      start = t;
      start->previous = last;
      last->next = start;
   }
}


void dcll::last_insert() {
   int val;
   cout<<"Enter value: ";
   cin>>val;
   struct nod *t;
   t = create_node(val);
   if (start == last && start == NULL) {
      start = last = t;
      start->next= last->next = NULL;
      start->previous = last->previous= NULL;
   } else {
      last->next= t;
      t->previous= last;
      last = t;
      start->previous = last;
      last->next= start;
   }
}


void dcll::position_insert() {
   int val, pos, i;
   cout<<"Enter value: ";
   cin>>val;
   cout<<"Enter the position of the element: ";
   cin>>pos;
   struct nod *t, *s, *ptr;
   t = create_node(val);
   if (start == last && start == NULL) {
      if (pos == 1) {
         start = last = t;
         start->next = last->next = NULL;
         start->previous = last->previous = NULL;
      } else {
         cout<<"Position out of range"<<endl;
         count--;
         return;
      }
   } else {
      if (count < pos) {
         cout<<"Position out of range"<<endl;
         count--;
         return;
      }
      s = start;
      for (i = 1;i <= count;i++) {
         ptr = s;
         s = s->next;
         if (i == pos - 1) {
            ptr->next = t;
            t->previous= ptr;
            t->next= s;
            s->previous = t;
            break;
         }
      }
   }
}


void dcll::position_delete() {
   int pos, i;
   nod *ptr, *s;
   if (start == last && start == NULL) {
      cout<<"Underflow"<<endl;
      return;
   }
   cout<<"Enter the position of element to be delete: ";
   cin>>pos;
   if (count < pos) {
      cout<<"Position out of range"<<endl;
      return;
   }
   s = start;
   if(pos == 1) {
      count--;
      last->next = s->next;
      s->next->previous = last;
      start = s->next;
      free(s);
      cout<<"Element Deleted"<<endl;
      return;
   }
   for (i = 0;i < pos - 1;i++ ) {
      s = s->next;
      ptr = s->previous;
   }
   ptr->next = s->next;
   s->next->previous = ptr;
   if (pos == count) {
      last = ptr;
   }
   count--;
   free(s);
   cout<<"Element Deleted"<<endl;
}


void dcll::update() {
   int val, i, pos;
   if (start == last && start == NULL) {
      cout<<"List is empty"<<endl;
      return;
   }
   cout<<"Enter the position of element to be update: ";
   cin>>pos;
   cout<<"Enter the new value: ";
   cin>>val;
   struct nod *s;
   if (count < pos) {
      cout<<"Position out of range"<<endl;
      return;
   }
   s = start;
   if (pos == 1) {
      s->info = val;
      cout<<"Element Updated"<<endl;
      return;
   }
   for (i=0;i < pos - 1;i++) {
      s = s->next;
   }
   s->info = val;
   cout<<"Element Updated"<<endl;
}


void dcll::search() {
   int pos = 0, val, i;
   bool flag = false;
   struct nod *s;
   if (start == last && start == NULL) {
      cout<<"List is empty"<<endl;
      return;
   }
   cout<<"Enter the value that you want to search: ";
   cin>>val;
   s = start;
   for (i = 0;i < count;i++) {
      pos++;
      if (s->info == val) {
         cout<<"Element "<<val<<" found at position: "<<pos<<endl;
         flag = true;
      }
      s = s->next;
   }
   if (!flag)
      cout<<"Element not found"<<endl;
}


void dcll::display() {
   int i;
   struct nod *s;
   if (start == last && start == NULL) {
      cout<<"List is empty"<<endl;
      return;
   }
   s = start;
   for (i = 0;i < count-1;i++) {
      cout<<s->info<<"  ";
      s = s->next;
   }
   cout<<s->info<<endl;
}


void dcll::reverse() {
   if (start == last && start == NULL) {
      cout<<"List is empty"<<endl;
      return;
   }
   struct nod *p1, *p2;
   p1 = start;
   p2 = p1->next;
   p1->next = NULL;
   p1->previous= p2;
   while (p2 != start) {
      p2->previous = p2->next;
      p2->next = p1;
      p1 = p2;
      p2 = p2->previous;
   }
   last = start;
   start = p1;
   cout<<"List Reversed"<<endl;
}