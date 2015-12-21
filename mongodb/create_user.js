db.createUser(
  {
    user: "bdep",
    pwd: "pntmdcg",
    roles: [ { role: "root", db: "admin" } ]
  }
);
db.createUser(
  {
    user: "spider",
    pwd: "pntmdcg",
    roles: [ 
        {
            role: "readWrite",
            db: "test"
        },
        {
            role: "userAdminAnyDatabase",
            db: "admin"
        },
        {
            role: "readWrite",
            db: "pyspider_taskdb"
        },
        {
            role: "readWrite",
            db: "pyspider_projectdb"
        },
        {
            role: "readWrite",
            db: "pyspider_resultdb"
        }
    ]
  }
);
