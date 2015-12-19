package com.baia.nword.SortMap;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

/**
 * @author baisun
 * @date 2014-08-31
 * 
 */
public class SortMap extends Mapper<LongWritable, Text, IntWritable, Text> {
	IntWritable mapKey = new IntWritable();
	private Text mapValue = new Text();

	@Override
	public void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {

		String[] sline = value.toString().split(String.valueOf('\t'));

		try {
			mapKey.set(Integer.parseInt(sline[1]));
			mapValue.set(sline[0]);
			context.write(mapKey, mapValue);

		} catch (Exception e) {
			System.err.println("SortMap err");
		}
	}
}