import random, string, datetime, os
import faker
from faker import Faker
fk = Faker()
from .models import Cloths
from django.db import transaction
from django.contrib.auth.models import Group, User

def gentestdata():
    with transaction.atomic():
        for i in range (10000):
            newCloths = Cloths()
            newCloths.brand = random.choice(('prada', 'prototype', 'balenciaga', 'yori sports', 'rick owens', 'vetements'))
            newCloths.category = random.choice(('boots', 'jeans', 't-shirt', 'snickers', 'zip', 'jacket'))
            newCloths.price = random.uniform(50, 3000)
            newCloths.color = random.choice(('red', 'black', 'white', 'grey', 'yellow', 'pink'))
            newCloths.used = random.random() > 0.4
            newCloths.season = fk.date_between(start_date="-25y", end_date="+1y")
            newCloths.description = fk.text(max_nb_chars=120)
            newCloths.save()
        print('OK DATA GENERATED')

        
#python manage.py shell
#from mainapp.generate_data import *
#gentestdata()
