template<class T>
class LinkList{
private:
    T Data;
    LinkList *Next;
    LinkList *Front;
    LinkList* get_back(){
        LinkList *Node = this;
        while (Node->Next != nullptr){
            Node = Node->Next;
        }
        return Node;
    }
public:
    LinkList();
    void push_back(T data);
    void insert(T data, LinkList* old, bool front_back);
    LinkList* get_node(T data);
    bool isExist(T data);
    void erasa(LinkList *Node);
    void changeData(T newData, LinkList* node);
};

template<class T>
void LinkList<T>::changeData(T newData, LinkList *node) {
    node->Data = newData;
}

template<class T>
void LinkList<T>::erasa(LinkList *Node) {
    LinkList *tempNext = Node->Next,*tempFront = Node->Front;
    tempNext->Front = tempFront;
    tempFront->Next = tempNext;
    delete Node;
}

template<class T>
bool LinkList<T>::isExist(T data) {
    LinkList *node = this;
    while (node->Next!= nullptr){
        if (node->Data == data) return true;
        node = node->Next;
    }
    return false;
}

template<class T>
LinkList<T>* LinkList<T>::get_node(T data) {
    LinkList *node = this;
    while (node->Next!= nullptr){
        if (node->Data == data) return node;
        node = node->Next;
    }
    return nullptr;
}

template<class T>
void LinkList<T>::insert(T data, LinkList *old, bool front_back) {
    //front_back指定插入方向，true插入到old前，不然插入到old后
    LinkList *New = new LinkList();
    New->Data = data;
    LinkList *temp;
    if (front_back){
        temp = old->Front;
        old->Front = New;
        temp->Next = New;
    } else {
        temp = old->Next;
        old->Next = New;
        temp->Front = New;
    }
}

template<class T>
LinkList<T>::LinkList() {
    Next = nullptr;
    Front = nullptr;
    Data = nullptr;
}

template<class T>
void LinkList<T>::push_back(T data) {
    LinkList *Node = get_back();
    LinkList *New = new LinkList();
    New->Data = data;
    Node->Next = New;
    New->Front = Node;
}
