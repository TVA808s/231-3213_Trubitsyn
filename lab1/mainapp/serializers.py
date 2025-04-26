from rest_framework import serializers
from .models import Cloths


class ClothsSerializer(serializers.ModelSerializer):
    def to_representation(self, instance : Cloths):
        jsonDict = super().to_representation(instance)
        jsonDict["season"] = instance.season.strftime("%B %Y")
        return jsonDict
    
    # def to_internal_value(self, data):
    #     return super().to_internal_value(data)

    class Meta:
        model = Cloths
        fields = '__all__'
    
    price = serializers.DecimalField(max_digits=10, decimal_places=2, coerce_to_string=False)
    season = serializers.DateField(input_formats=["%Y-%m-%d"], format="%B %Y")
    

