USE amazon;

ALTER TABLE mijozlar ADD CONSTRAINT unq_telefon_raqam UNIQUE (telefon_raqam);
