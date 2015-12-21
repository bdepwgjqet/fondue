/*
use admin;
db.createUser(
  {
    user: "bdep",
    pwd: "pntmdcg",
    roles: [ 
//        {
//            role: "userAdminAnyDatabase",
//            db: "admin"
//        },
        { 
            role: "root", db: "admin" 
        } 
    ]
  }
);
*/
db = db.getSiblingDB("pyspider_taskdb");
db.createUser(
  {
    user: "spider",
    pwd: "pntmdcg",
    roles: [ 
        {
            role: "readWrite",
            db: "pyspider_taskdb"
        }
    ]
  }
);
db = db.getSiblingDB("pyspider_projectdb");
db.createUser(
  {
    user: "spider",
    pwd: "pntmdcg",
    roles: [ 
        {
            role: "readWrite",
            db: "pyspider_projectdb"
        }
    ]
  }
);
db = db.getSiblingDB("pyspider_resultdb");
db.createUser(
  {
    user: "spider",
    pwd: "pntmdcg",
    roles: [ 
        {
            role: "readWrite",
            db: "pyspider_resultdb"
        }
    ]
  }
);
