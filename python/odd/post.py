#!/bin/python

import requests

url = "http://entityrepository.binginternal.com/EnrichmentService/EnrichedVersion?serviceName=ApplySatoriIdEnrichmentService"
payload = {"Format":"Triple", "CustomerId":"Satori", "EnvironmentName": "production", "Name":"PrePublish"}
 
r = requests.post(url,data=payload)

print r.text
