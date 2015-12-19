package com.baia.nword.WordCount;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

import com.baia.nword.Comparators.DescendingIntComparable;
import com.baia.nword.CountMap.CountMap;
import com.baia.nword.CountReduce.CountReduce;
import com.baia.nword.SortMap.SortMap;
import com.baia.nword.SortReduce.SortReduce;

/**
 * @author baisun
 * @date 2014-08-31
 * 
 */
public class WordCount {

	public static int run(String[] args) throws Exception {
		Configuration conf = new Configuration();
		conf.set("preTimeTag", args[2]);

		Path tmpDir = new Path(new String("wordcount-tmpdir-"
				+ System.currentTimeMillis()));

		Job job = new Job(conf, "word count");

		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(IntWritable.class);

		job.setMapperClass(CountMap.class);
		job.setReducerClass(CountReduce.class);

		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);

		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, tmpDir);

		job.waitForCompletion(true);

		Job sortJob = new Job(conf, "count sort");

		sortJob.setOutputKeyClass(IntWritable.class);
		sortJob.setOutputValueClass(Text.class);

		sortJob.setMapperClass(SortMap.class);
		sortJob.setReducerClass(SortReduce.class);

		sortJob.setInputFormatClass(TextInputFormat.class);
		sortJob.setOutputFormatClass(TextOutputFormat.class);

		sortJob.setSortComparatorClass(DescendingIntComparable.class);

		FileInputFormat.addInputPath(sortJob, tmpDir);
		FileOutputFormat.setOutputPath(sortJob, new Path(args[1]));

		sortJob.waitForCompletion(true);

		return 0;
	}

	public static void main(String[] args) throws Exception {
		if (args.length != 3) {
			System.err.println("err Parameters : input output prehours");
			System.exit(-1);
		}

		int exitRes = run(args);
		System.exit(exitRes);
	}
}