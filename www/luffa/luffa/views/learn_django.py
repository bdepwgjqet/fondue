from django.http import HttpResponse
from django.http import Http404
from django.template.loader import get_template
from django.template import Context
from django.shortcuts import render_to_response
import datetime

def hello(request):
    return HttpResponse("Hello world")

def current_datetime(request):
    now = datetime.datetime.now();

#    t = get_template('current_datetime.html')
#    html = t.render(Context({'current_date': now}))
#    return HttpResponse(html)

#    return render_to_response('current_datetime.html',{'current_date': now})

    return render_to_response('time/current_datetime.html', locals())

def hours_ahead(request,offset):
    try:
        hour_offset = int(offset)
    except ValueError:
        raise Http404()
    next_time = datetime.datetime.now() + datetime.timedelta(hours=hour_offset)

    return render_to_response('time/hours_ahead.htm', locals())

#    html = "<html><body>In %s hours, it will be %s.</body></html>" % (offset, dt)
#    return HttpResponse(html)
