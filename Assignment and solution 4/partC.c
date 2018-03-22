
struct myClass{
    int m_x;
    void (*func)(struct myClass *, int);
};

struct Derived{
    struct myClass *super;
    void (*func)(struct Derived *, int);
};

struct Derived2{
  struct myClass *super;
  int m_y;
  void (*func)(struct Derived2 *, int);
};

void add(struct myClass *self, int y){
    self->m_x = self->m_x+y;
}

void xor(struct Derived *self, int y){
    self->super->m_x = self->super->m_x^y;
}

void add2(struct Derived2 *self, int y){
    add(self->super, y);
    self->m_y=y;
}