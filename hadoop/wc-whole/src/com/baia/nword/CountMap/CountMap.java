package com.baia.nword.CountMap;

import java.io.IOException;
import java.util.Date;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

/**
 * @author baisun
 * @date 2014-08-31
 * 
 */
public class CountMap extends Mapper<LongWritable, Text, Text, IntWritable> {
	private final static IntWritable one = new IntWritable(1);
	private Text word = new Text();

	@Override
	public void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {

		String[] sline = value.toString().split(String.valueOf((char) 1));

		try {
			Date currentDate = new Date(System.currentTimeMillis());
			long curDate = currentDate.getTime() / 1000;
			long timeStamp = Long.parseLong(sline[sline.length - 1]);

			Configuration conf = context.getConfiguration();
			long preTimeTag = Long.parseLong(conf.get("preTimeTag"));
			long preTime = preTimeTag * 3600;

			if (timeStamp >= curDate - preTime) {
				for (int i = 0; i < sline.length - 1; i++) {
					word.set(sline[i]);
					context.write(word, one);
				}
			}
		} catch (Exception e) {
			System.err.println("CountMap err");
		}

	}
}
