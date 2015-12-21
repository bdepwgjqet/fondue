db.updateUser (
    "pyspider",
    {
        roles : [
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
