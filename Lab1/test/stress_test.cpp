#include "stress_test.h"

using namespace std;

string stress_test::file = "C:\\Users\\wakam\\Desktop\\file.data";

static void load_nodes(database *base, const string &name, const string &n_class, size_t amount) {
    node n("", "");
    while (amount != 0){
        n.node_name = name + to_string(base->information.node_count);
        n.node_class = n_class;
        base->add_node(n);
        amount--;
    }
}

static void empty_base_load_test() {
    cout << "Empty base load test started." << endl;

    database base(stress_test::file);
    base.create();

    time_t start_t, end_t;
    time(&start_t);
    load_nodes(&base, "node", "Object", 10000);
    time(&end_t);

    base.save();

    cout << "Start time: " << start_t << endl;
    cout << "End time: " << end_t << endl;
    cout << "Time to add 100000 node to EMPTY base: " << end_t - start_t << endl;
}

static void filled_base_load_test() {
    cout << "Filled base load test started." << endl;

    database base(stress_test::file);
    base.create();
    time_t start_t, end_t;
    load_nodes(&base, "node", "Object", 50000);

    time(&start_t);
    load_nodes(&base, "test", "Object", 10000);
    time(&end_t);

    base.save();

    cout << "Start time: " << start_t << endl;
    cout << "End time: " << end_t << endl;
    cout << "Time to add 100000 node to FILLED base: " << end_t - start_t << endl;
}

static void insert_op_test() {
    cout << "Insert operation test started." << endl;
    for (size_t i = 1; i < 25; i++) {
        database base(stress_test::file);
        base.create();
        load_nodes(&base, "node", "Object", 1000 * i);
        base.save();

        auto start_t = std::chrono::high_resolution_clock::now();
        load_nodes(&base, "test_node", "Object", 1000);
        auto end_t = std::chrono::high_resolution_clock::now();
        auto time = end_t - start_t;

        cout << "Time to insert " << 1000 * i << " node to base: " << time / chrono::milliseconds(1) << endl;
    }
}

static void select_op_test() {
    cout << "Select operation test started." << endl;

    for (size_t i = 1; i < 25; i++) {
        database base(stress_test::file);
        base.create();
        load_nodes(&base, "node", "Object", 1000 * i);
        base.save();

        auto start_t = std::chrono::high_resolution_clock::now();
        for (size_t j = 0; j < 1000; j++) {
            string name = "node" + to_string(j);
            node res = base.get_node(name);
        }
        auto end_t = std::chrono::high_resolution_clock::now();
        auto time = end_t - start_t;

        cout << "Time to select " << 1000 * i << " node to base: " << time / chrono::milliseconds(1) << endl;
    }
}

static void delete_op_test() {
    cout << "Delete operation test started." << endl;
    for (size_t i = 1; i < 25; i++) {
        database base(stress_test::file);
        base.create();
        load_nodes(&base, "node", "Object", 1000 * i);
        base.save();

        auto start_t = std::chrono::high_resolution_clock::now();
        for (size_t j = 0; j < 1000; j++) {
            string name = "node" + to_string(j);
            base.delete_node(name);
        }
        auto end_t = std::chrono::high_resolution_clock::now();
        auto time = end_t - start_t;

        cout << "Time to delete " << 1000 * i << " node to base: " << time / chrono::milliseconds(1) << endl;
    }
}

static void update_op_test() {
    cout << "Update operation test started." << endl;
    for (size_t i = 1; i < 25; i++) {
        database base(stress_test::file);
        base.create();
        load_nodes(&base, "node", "Object", 1000 * i);
        base.save();

        auto start_t = std::chrono::high_resolution_clock::now();
        for (size_t j = 0; j < 1000; j++) {
            node n = node("test" + to_string(j), "Object");
            base.update_node("node" + to_string(j), n);
        }
        auto end_t = std::chrono::high_resolution_clock::now();
        auto time = end_t - start_t;

        cout << "Time to update " << 1000 * i << " node to base: " << time / chrono::milliseconds(1) << endl;
    }
}

void stress_test::run_tests() {
    empty_base_load_test();
    filled_base_load_test();
    insert_op_test();
    select_op_test();
    delete_op_test();
    update_op_test();
}