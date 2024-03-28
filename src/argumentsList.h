class keyval{
public:

    keyval(keyval *pr, keyval *nxt){
        pre = pr;
        next = nxt;
    }

    ~keyval(){

    }

    keyval *pre;
    keyval *next;

    String key;
    String val;
};

class argumentsList{
    public:
    argumentsList();


    private:
    keyval head;

};