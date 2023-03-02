#include "test.h"

using namespace std;

string test::file = "../file.data";

static void add_test(){
    cout << "Started Add test." << endl;

    database base(test::file);
    base.create();

    node n("Laxiqa", "Object");
    n.add_prop("vigaj", property(123));
    n.add_prop("nonusik", property("String_1"));
    n.add_prop("kiqod", property(true));
    n.add_prop("covutebym", property(235.623f));
    n.add_relationship("jyrys", relationship("Laxiqa", "Xasyfe"));

    base.add_node(n);
    string name = "Laxiqa";
    node res = base.get_node(name);

    assert(res.get_prop("vigaj").get_int() == 123);
    assert(res.get_prop("nonusik").get_string() == "String_1");
    assert(res.get_prop("kiqod").get_bool() == true);
    assert(res.get_prop("covutebym").get_float() == 235.623f);
    assert(res.get_relationship("jyrys").related_with == "Xasyfe");

    assert(base.information.node_count == 1);
    assert(base.information.node_names.find("Laxiqa") != base.information.node_names.end());
    assert(base.information.node_classes.find("Object") != base.information.node_classes.end());
    assert(base.information.free.empty());

    cout << "Add test passed." << endl;
}


static void delete_test(){
    cout << "Started Delete test." << endl;

    database base(test::file);
    base.create();

    node n("Jejykiv", "Object");
    n.add_prop("meguvaju", property(123));
    n.add_prop("cilevoj", property("String_1"));
    n.add_prop("guqyru", property(true));
    n.add_prop("aqasox", property(235.623f));
    n.add_relationship("vuduna", relationship("Jejykiv", "Laxiqa"));

    base.add_node(n);
    string name = "Jejykiv";
    node res = base.get_node(name);
    base.delete_node(res.node_name);

    assert(base.information.node_names.find(res.node_name) == base.information.node_names.end());
    assert(base.information.node_classes.find("Object") == base.information.node_classes.end());
    assert(base.information.free[0] == res.id);

    cout << "Delete test passed." << endl;
}

static void update_test(){
    cout << "Started Update test." << endl;

    database base(test::file);
    base.create();

    node n("Majib", "Object");
    n.add_prop("posak", property(123));
    n.add_prop("oqymu", property("String_1"));
    n.add_prop("saselip", property(true));
    n.add_prop("miqyfyl", property(235.623f));
    n.add_relationship("relyt", relationship("Majib", "Puwosor"));

    base.add_node(n);

    node n_n("Jagegedip", "Car");
    n_n.add_prop("cyl", property("String_2"));
    n_n.add_prop("nojifan", property(456));
    n_n.add_prop("rujeqa", property(235.624f));
    n_n.add_prop("gorehy", property(true));
    n_n.add_relationship("muratu", relationship("Jagegedip", "Laxiqa"));

    base.update_node("Majib", n_n);

    node res = base.get_node("Jagegedip");

    assert(res.get_prop("cyl").get_type() == property::STRING);
    assert(res.get_prop("nojifan").get_type() == property::INT);
    assert(res.get_prop("rujeqa").get_type() == property::FLOAT);
    assert(res.get_prop("gorehy").get_type() == property::BOOL);

    assert(res.get_prop("cyl").get_string() == "String_2");
    assert(res.get_prop("nojifan").get_int() == 456);
    assert(res.get_prop("rujeqa").get_float() == 235.624f);
    assert(res.get_prop("gorehy").get_bool() == true);

    cout << "Update test passed." << endl;
}

void test::run_tests(){
    add_test();
    delete_test();
    update_test();
}