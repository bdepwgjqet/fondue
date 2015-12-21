package com.baia.nword.Comparators;

import java.nio.ByteBuffer;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.WritableComparable;
import org.apache.hadoop.io.WritableComparator;

/**
 * @author baisun
 * @date 2014-8-31
 * 
 */
public class DescendingIntComparable extends WritableComparator {

	public DescendingIntComparable() {
		super(IntWritable.class);
	}

	@SuppressWarnings("rawtypes")
	@Override
	public int compare(WritableComparable a, WritableComparable b) {
		return super.compare(a, b) * (-1);
	}

	@Override
	public int compare(byte[] b1, int s1, int l1, byte[] b2, int s2, int l2) {

		Integer v1 = ByteBuffer.wrap(b1, s1, l1).getInt();
		Integer v2 = ByteBuffer.wrap(b2, s2, l2).getInt();

		return v1.compareTo(v2) * (-1);
	}

}
