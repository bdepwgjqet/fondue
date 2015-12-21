db.updateUser (
    "spider",
    {
        roles : [
            {
                role: "userAdminAnyDatabase",
                db: "admin"
            }
        ]
    }
);
