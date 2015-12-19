package com.baia.nword.SortReduce;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

/**
 * @author baisun
 * @date 2014-08-31
 * 
 */
public class SortReduce extends Reducer<IntWritable, Text, Text, IntWritable> {

	@Override
	public void reduce(IntWritable key, Iterable<Text> values, Context context)
			throws IOException, InterruptedException {
		for (Text text : values) {
			context.write(text, key);
		}
	}
}