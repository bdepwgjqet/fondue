// db.system.users.remove(
//     {
//         "_id":"admin.spider"
//     }
// );



db.system.users.remove(
    {
        "_id":"pyspider_taskdb.spider"
    }
);

db.system.users.remove(
    {
        "_id":"pyspider_projectdb.spider"
    }
);

db.system.users.remove(
    {
        "_id":"pyspider_resultdb.spider"
    }
);
