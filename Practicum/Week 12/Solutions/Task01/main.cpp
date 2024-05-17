#include "Directory.hpp"
#include "File.hpp"
// #include "Entity.hpp"


int main()
{
    Directory f("main");

    Directory fold("fold");
    Entity* foldptr = &fold;

    Directory fold2("fold2");
    Entity* foldptr2 = &fold2;

    Directory fold3("fold3");
    Entity* foldptr3 = &fold3;

    Entity* f1 = new File("a");
    Entity* f2 = new File("b");
    Entity* f3 = new File("c");
    Entity* f4 = new File("d", "1111");


    fold3.addEntity(f1);
    fold3.addEntity(f2);
    fold3.addEntity(f3);

    fold.addEntity(f1);
    fold.addEntity(f2);
    fold.addEntity(f3);
    fold.addEntity(foldptr3);
    fold.addEntity(f4);

    f.addEntity(foldptr);
    f.addEntity(foldptr2);
    f.display();

    Entity* d = f.find("a");
    std::cout << d->getName() << std::endl;
    std::cout << f.getSize()<< " Bytes" << std::endl;
    std::cout << f.getFilesCount() << " Files" << std::endl;


    return 0;
}
