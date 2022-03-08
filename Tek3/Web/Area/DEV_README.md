/!\ les tokens pour acceder a l'api sont en Bearer /!\

# HOW TO ADD A REACTION

REACTION === ACTION/REACTION

Route: '/actions_reactions/add_reaction'
Method: POST
body: {
  "action_reaction": {"action": {"name": ""}, "reaction": {"name": ""}},
}
ex: 
body: {
    "action_reaction": {"action": {"name": "temperature", "city": "Montpellier", "operand": ">=", "value": 6}, "reaction": {"name": "turn_on_light", "device": "bedroom"}}
}

# HOW TO GET A REACTION

Route: '/actions_reactions/retrieve'
Method: GET
(TROP CHIANT A CHANGER DONC CA RESTERA SANS DOUTE COMME CA) (OUI C UN TABLEAU DANS UN TABLEAU)
return -> 
{
  "actions_reactions": [
    [
      1,
      3,
      "{\"name\": \"temperature\", \"city\": \"Montpellier\", \"operand\": \">=\", \"value\": 10}",
      "{\"name\": \"test_print\", \"value\": \"la temperature a montpellier est superieure a 10 degres !!!!\"}",
      null
    ],
    [
      2,
      3,
      "{\"name\": \"temperature\", \"city\": \"Montpellier\", \"operand\": \">=\", \"value\": 6}",
      "{\"name\": \"test_print\", \"value\": \"la temperature a montpellier est superieure a 6 degres !!!!\"}",
      null
    ]
  ]
}

actions_reactions[0][0] = actions_reactions_id
actions_reactions[0][1] = user_id
actions_reactions[0][2] = action
actions_reactions[0][3] = reaction
actions_reactions[0][4] = last_updated_at (osef de celui la)


# HOW TO DELETE A REACTION

Prior: faut que tu ai l'id de l'action_reaction
Route: '/actions_reactions/delete_reaction'
Method: POST

body:
{
  "action_id": 0
}

# HOW TO SUBSCRIBE TO A SERVICE

Route: '/subscribe/{service}' (ici le nom du service sera par exemple 'office')
Method: POST
body:
{
  "token": "string"
}

(voir les services dispo pour sub dans le fichier '/server/app/routes/subscribe.py')