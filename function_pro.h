u8 password ();
void print (patient * head_ref);
void add_func (patient ** head_ref , u32 pos, u32 na [] ,u32 ag ,u32 ge [],u32 id_p);
void enter_data (u32 name [] , u32 * age ,u32 gender[], u32* id );
u8 check_id (patient *head_ref ,u8 id);
void edit (patient ** head_ref , u32 id);
void slots (slot ** head_ref);
void display_slot (slot * head_ref );
void reserve (slot ** head_ref,u32 id , u32 pos_slot );
void cancel_reserve (slot ** head_ref,u32 pos_slot );
void view_patient(patient * head_ref,u32 id);
void display_reserv (slot * head_ref );