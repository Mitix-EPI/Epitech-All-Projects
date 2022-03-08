USE area;
INSERT INTO users (mail, password) VALUES ('mail@mail.com', 'password');
USE area;
INSERT INTO actions_reactions (user_id, action, reaction) VALUES (1, '{"name": "temperature", "city": "Montpellier", "operand": ">=", "value": 10}', '{"name": "test_print", "value": "la temperature a montpellier est superieure a 10 degres !!!!"}');
USE area;
INSERT INTO actions_reactions (user_id, action, reaction) VALUES (1, '{"name": "temperature", "city": "Montpellier", "operand": ">=", "value": 6}', '{"name": "test_print", "value": "la temperature a montpellier est superieure a 6 degres !!!!"}');