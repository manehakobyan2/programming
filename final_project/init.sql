--Creating the table for login register and also giving them intial money value
CREATE TABLE IF NOT EXISTS users 
(
    id INTEGER PRIMARY KEY AUTOINCREMENT, --Id set to automatically move to next
   username TEXT UNIQUE NOT NULL,   -- defining username type text
   password TEXT NOT NULL, -- password type text
    total_balance REAL DEFAULT 100000.00 --balance on the card the balance at first is by default 100000 drams
);

--table for slots 
CREATE TABLE slots 
(
    slot_id INTEGER PRIMARY KEY AUTOINCREMENT,  --creating slot id
    user_id INTEGER NOT NULL, --using user id to identify user with their slots
    slot_name TEXT NOT NULL, --Naming the slot
    balance REAL DEFAULT 0.0, --balance to add to slot value
    FOREIGN KEY (user_id) REFERENCES users(id), --taking from other table 
    UNIQUE(user_id, slot_name) --making sure that slot_name defined by the same user is not same
);
